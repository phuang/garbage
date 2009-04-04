#!/usr/bin/env python
# vim: et sts=4 :
# Copyright: Red Hat 2009

operators = ["?+=", "?<=", "?=", "+=", "<=", "="]


class Block:
    "Block data"
    def __init__(self):
        self.__values = []
        self.__filters = []

    def append_value(self, value):
        self.__values.append(value)

    def append_variants(self, variants):
        self.__values.append(variants)

    def add_filter(self, filter, remove):
        self.__filters.append((filter, remove))

    def add_filters(self, filters, remove):
        for filter in filters:
            self.add_filter(filter, remove)

    def get_values(self):
        return self.__values

class Variants:
    "Variants data"
    def __init__(self):
        self.__blocks = {}

    def append_block(self, name, block):
        self.__blocks[name] = block

    def filter(self, filter, remove):
        pass

    def keys(self):
        return self.__blocks.keys()

    def __getitem__(self, i):
        return self.__block,__getitem__(i)

class ExceptionBlock(Block):
    "Exception block"
    def __init__(self, name, block):
        Block.__init__(self)
        self.__name = name
        self.__values = block.get_values()
        

def pre_process_line(f):
    "remove comment and empty line -> lines"
    for line in f:
        line = line.expandtabs()
        strip_line = line.strip()
        if not strip_line:
            continue
        if strip_line.startswith("#"):
            continue
        yield line.strip("\n")

def process_indent(f):
    "process indent, -> indent, line"
    for line in pre_process_line(f):
        indent = 0
        for c in line:
            if c != ' ':
                yield indent / 4, line.strip()
                break
            indent += 1

def parse_variants(lines, prev_indent=-1):
    "parse variants block"
    variants = Variants()

    while lines:
        indent, line = lines.pop(0)
        if indent <= prev_indent:
            lines.insert(0, (indent, line))
            break
        if not line.startswith("-"):
            raise Exception, "ErrorVariant"
        line = line.strip("- ")
        name = line
        variants.append_block(name, parse_lines(lines, prev_indent + 1))
    return variants

def parse_lines(lines, prev_indent=-1):
    block = Block()
    while lines:
        indent, line = lines.pop(0)
        if indent <= prev_indent:
            lines.insert(0, (indent, line))
            break

        # parse variants
        if line == "variants:":
            block.append_variants(parse_variants(lines, prev_indent + 1))
            continue

        # parse values
        line.split()
        if  line.startswith("no ") or line.startswith("only "):
            op, filter = line.split(" ", 1)
            
            block.add_filters(filter.split(), op == "no")
            continue

        if line.endswith(":"):
            name = line.strip(":")
            block.append_value(ExceptionBlock(name, parse_lines(lines, prev_indent + 1)))
            continue

        for op in operators:
            if op in line:
                break
        else:
            raise Exception, "Error Value"
        
        name, value = [i.strip() for i in line.split(op, 1)]
        block.append_value((name, op, value))

    return block
        

def parse(f):
    lines = list(process_indent(f))

    return parse_lines(lines);

def main():
    return parse(file("kvm_tests.cfg"))


if __name__ == "__main__":
    main()


