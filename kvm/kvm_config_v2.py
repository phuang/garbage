#!/usr/bin/env python
# vim: et 
# Copyright: Red Hat 2009

import copy
import re
import os
import sys
import StringIO
from ExDict import ExDict

def dict_list_copy(l):
    nl = map(lambda d:ExDict(d), l)
    return nl

deepcopy = copy.deepcopy

class config:

    """This class parses an input file or string and generates a list of dicts."""

    def __init__(self, filename=None, debug=False):
        """Initialize the list and optionally parse filename."""
        self.list = [ExDict({"name": "", "shortname": "", "depend": []})]
        self.debug = debug
        if filename:
            self.parse_file(filename)

    def set_debug(self, debug=False):
        """Enable or disable debugging."""
        self.debug = debug

    def parse_file(self, filename):
        """Parse filename, return the resulting list and store it in .list.

        If filename does not exist, raise an exception.
        """
        if not os.path.exists(filename):
            raise Exception, "File %s not found" % filename
        file = open(filename, "r")
        self.list = self.parse(file, self.list)
        file.close()
        return self.list

    def parse_string(self, str):
        """Parse a string, return the resulting list and store it in .list."""
        file = StringIO.StringIO(str)
        self.list = self.parse(file, self.list)
        file.close()
        return self.list

    def get_list(self):
        """Return the list of dictionaries.

        This should probably be called after parsing something.
        """
        return self.list

    def match(self, filter, dict):
        """Return True if dict matches filter.

        filter -- a regular expression
        """
        filter = re.compile("(\\.|^)" + filter + "(\\.|$)")
        return filter.search(dict["name"]) != None

    def filter(self, filter, list=None):
        """Filter a list of dicts.

        filter -- a regular expression
        """
        if list == None:
            list = self.list
        filtered_list = []
        for dict in list:
            if self.match(filter, dict):
                filtered_list.append(dict)
        return filtered_list

    # Currently unused, will be removed if it remains unused
    def get_match_block_indices(self, filter, list=None):
        if list == None:
            list = self.list
        block_list = []
        prev_match = False
        for index in range(len(list)):
            dict = list[index]
            if self.match(filter, dict):
                if not prev_match:
                    block_list.append([index])
                prev_match = True
            else:
                if prev_match:
                    block_list[-1].append(index)
                prev_match = False
        if prev_match:
            block_list[-1].append(len(list))
        return block_list

    def split_and_strip(self, str, sep="="):
        """Split str and strip quotes from the resulting parts."""
        temp = str.split(sep)
        for i in range(len(temp)):
            temp[i] = temp[i].strip()
            temp[i] = temp[i].strip("\"\'")
        return temp

    def get_next_line(self, file):
        """Get the next non-empty, non-comment line in file.

        If no line is available, return None.
        """
        while True:
            line = file.readline()
            if line == "": return None
            stripped_line = line.strip()
            if len(stripped_line) > 0 \
                    and not stripped_line.startswith('#') \
                    and not stripped_line.startswith('//'):
                return line

    def get_next_line_indent(self, file):
        """Return the indent level of the next non-empty, non-comment line in file.

        If no line is available, return -1.
        """
        pos = file.tell()
        line = self.get_next_line(file)
        if not line:
            file.seek(pos)
            return -1
        line = line.expandtabs()
        indent = 0
        while line[indent] == ' ':
            indent += 1
        file.seek(pos)
        return indent

    def add_name(self, str, name, append=False):
        """Add name to str with a separator dot and return the result.

        If append is True, append name to str.  Otherwise, pre-pend name to str.
        """
        if str == "":
            return name
        # Append?
        elif append:
            return str + "." + name
        # Prepend?
        else:
            return name + "." + str

    def debug_print(self, indent, str1, str2=""):
        """Nicely print indented text.  For internal use."""
        if indent < 0:
            indent = 0
        while indent > 0:
            str1 = " " + str1
            indent -= 1
        if str2:
            str = "%-50s ---> %s" % (str1, str2)
        else:
            str = str1
        print str

    def parse(self, file, list=None, restricted=False, prev_indent=-1):
        """Parse a file-like object.

        file -- a file-like object
        list -- a list of dicts to operate on (list is modified in place
            and should not be used after the call)
        restricted -- if True, operate in restricted mode (prohibit 'variants')
        prev_indent -- the indent level of the "parent" block

        Read and parse lines from file until a line with an indent level lower than
        or equal to prev_indent is encountered.
        Return the resulting list of dicts.

        Note that list is destroyed and should not be used after the call.  Only
        the returned list should be used.
        """
        if list == None:
            list = deepcopy(self.list)

        while True:
            indent = self.get_next_line_indent(file)
            if indent <= prev_indent:
                break
            line = self.get_next_line(file).strip()

            len_list = len(list)

            # Look for a known operator in the line
            operators = ["?+=", "?<=", "?=", "+=", "<=", "="]
            op_found = None
            for op in operators:
                if op in line:
                    op_found = op
                    break

            # Found an operator?
            if op_found:
                if self.debug and not restricted:
                    self.debug_print(indent, line, "Parsing operator (%d dicts in current context)" % len_list)
                (left, value) = self.split_and_strip(line, op_found)
                filters_and_key = self.split_and_strip(left, ":")
                filters = filters_and_key[:-1]
                key = filters_and_key[-1]
                filtered_list = list
                for filter in filters:
                    filtered_list = self.filter(filter, filtered_list)
                # Apply the operation to the filtered list
                for dict in filtered_list:
                    if op_found == "=":
                        dict[key] = value
                    elif op_found == "+=":
                        dict[key] = dict.get(key, "") + value
                    elif op_found == "<=":
                        dict[key] = value + dict.get(key, "")
                    elif op_found.startswith("?") and dict.has_key(key):
                        if op_found == "?=":
                            dict[key] = value
                        elif op_found == "?+=":
                            dict[key] = dict.get(key, "") + value
                        elif op_found == "?<=":
                            dict[key] = value + dict.get(key, "")

            # Parse 'no' and 'only' statements
            elif line.startswith("no") or line.startswith("only"):
                words = line.split()
                if len(words) <= 1:
                    continue
                filters = words[1:]
                # Make a list of all dicts that match one or more of the filters
                filtered_list = []
                for filter in filters:
                    filtered_list += self.filter(filter, list)
                original_list = list[:]
                for dict in original_list:
                    if line.startswith("no"):
                        if dict in filtered_list:
                            list.remove(dict)
                    if line.startswith("only"):
                        if not dict in filtered_list:
                            list.remove(dict)
                if self.debug and not restricted:
                    self.debug_print(indent, line, "Parsing no/only (%d dicts in current context, %d remain)" % (len_list, len(list)))

            # Parse 'variants'
            elif line == "variants:":
                # 'variants' not allowed in restricted mode (inside an exception or inside subvariants)
                if restricted:
                    raise Exception, "Using variants in this context is not allowed"
                if self.debug and not restricted:
                    self.debug_print(indent, line, "Entering variants block (%d dicts in current context)" % len_list)
                list = self.parse_variants(file, list, subvariants=False, prev_indent=indent)

            # Parse 'subvariants' (the block is parsed for each dict separately)
            elif line == "subvariants:":
                if self.debug and not restricted:
                    self.debug_print(indent, line, "Entering subvariants block (%d dicts in current context)" % len_list)
                new_list = []
                # Remember current file position
                pos = file.tell()
                # Read the lines in any case
                self.parse_variants(file, [], subvariants=True, prev_indent=indent)
                # Iterate over the list...
                for index in range(len(list)):
                    # Revert to initial file position in this 'subvariants' block
                    file.seek(pos)
                    # Everything inside 'subvariants' should be parsed in restricted mode
                    new_list += self.parse_variants(file, list[index:index+1], subvariants=True, prev_indent=indent)
                list = new_list

            # Parse multi-line exceptions (the block is parsed for each dict separately)
            elif line.endswith(":"):
                if self.debug and not restricted:
                    self.debug_print(indent, line, "Entering multi-line exception block (%d dicts in current context outside exception)" % len_list)
                line = line.strip(":")
                new_list = []
                # Remember current file position
                pos = file.tell()
                # Read the lines in any case
                self.parse(file, [], restricted=True, prev_indent=indent)
                # Iterate over the list...
                for index in range(len(list)):
                    if self.match(line, list[index]):
                        # Revert to initial file position in this exception block
                        file.seek(pos)
                        # Everything inside an exception should be parsed in restricted mode
                        new_list += self.parse(file, list[index:index+1],
                                restricted=True, prev_indent=indent)
                    else:
                        new_list += list[index:index+1]
                list = new_list
        return list

    def modify_list_variants(self, list, name, dep_list, add_to_shortname):
        """Internal function.

        Make some modifications to list, as part of parsing a 'variants' block.
        """
        for dict in list:
            # Prepend name to the dict's 'name' field
            dict["name"] = self.add_name(dict["name"], name)
            # Prepend name to the dict's 'shortname' field
            if add_to_shortname:
                dict["shortname"] = self.add_name(dict["shortname"], name)
            # Prepend name to each of the dict's dependencies
            for i in range(len(dict["depend"])):
                dict["depend"][i] = self.add_name(dict["depend"][i], name)
            # Add new dependencies
            dict["depend"] += dep_list

    def modify_list_subvariants(self, list, name, dep_list, add_to_shortname):
        """Internal function.

        Make some modifications to list, as part of parsing a 'subvariants' block.
        """
        for dict in list:
            # Add new dependencies
            for dep in dep_list:
                dep_name = self.add_name(dict["name"], dep, append=True)
                dict["depend"].append(dep_name)
            # Append name to the dict's 'name' field
            dict["name"] = self.add_name(dict["name"], name, append=True)
            # Append name to the dict's 'shortname' field
            if add_to_shortname:
                dict["shortname"] = self.add_name(dict["shortname"], name, append=True)

    def parse_variants(self, file, list=None, subvariants=False, prev_indent=-1):
        """Parse a 'variants' or 'subvariants' block from a file-like object.

        file -- a file-like object
        list -- a list of dicts to operate on
        subvariants -- if True, parse in 'subvariants' mode; otherwise parse in
            'variants' mode
        prev_indent -- the indent level of the "parent" block

        Read and parse lines from file until a line with an indent level lower than
        or equal to prev_indent is encountered.
        Return the resulting list of dicts.
        """
        if list == None:
            list = self.list

        new_list = []

        while True:
            indent = self.get_next_line_indent(file)
            if indent <= prev_indent:
                break
            line = self.get_next_line(file).strip()

            # Get name and dependencies
            temp = line.strip("- ").split(":")
            name = temp[0]
            if len(temp) == 1:
                dep_list = []
            else:
                dep_list = temp[1].split()

            # See if name should be added to the 'shortname' field
            add_to_shortname = True
            if name.startswith("@"):
                name = name.strip("@")
                add_to_shortname = False

            temp_list = deepcopy(list)

            if subvariants:
                # If we're parsing 'subvariants', we need to modify the list first
                self.modify_list_subvariants(temp_list, name, dep_list, add_to_shortname)
                temp_list = self.parse(file, temp_list,
                        restricted=True, prev_indent=indent)
            else:
                # If we're parsing 'variants', we need to parse first and then modify the list
                if self.debug:
                    self.debug_print(indent, line, "Entering variant '%s' (variant inherits %d dicts)" % (name, len(list)))
                temp_list = self.parse(file, temp_list,
                        restricted=False, prev_indent=indent)
                self.modify_list_variants(temp_list, name, dep_list, add_to_shortname)

            new_list += temp_list
        return new_list


if __name__ == "__main__":
    if len(sys.argv) >= 2:
        filename = sys.argv[1]
    else:
        filename = os.path.join(os.path.dirname(sys.argv[0]), "kvm_tests.cfg")
    list = config(filename, debug=False).get_list()
    i = 0
    for dict in list:
        print "Dictionary #%d:" % i
        keys = dict.keys()
        keys.sort()
        for key in keys:
            print "    %s = %s" % (key, dict[key])
        i += 1
