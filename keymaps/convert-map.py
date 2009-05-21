#!/usr/bin/python
import sys

MODIFIERS = ('shift', 'numlock', 'altgr')

def main():

    try:
        fname = sys.argv[1]
    except:
        fname = "common"

    f = file(fname)

    keymap = {}
    includes = []

    for line in f:
        line = line.strip()
        if line.startswith("#"):
            continue
        if not line:
            continue
        tokens = line.split()
        if tokens[0] in ('sequence', 'map'):
            continue

        if tokens[0] == 'include':
            includes.append(tokens[1])
            continue
        
        keysym, keycode = tokens[:2]
        keycode = int(keycode, 16)
        modifiers = tokens[2:]

        if keycode not in keymap:
            keymap[keycode] = {'': None}

        if not modifiers:
            keymap[keycode][''] = keysym
            continue

        if len(modifiers) != 1:
            continue
        
        if modifiers[0] == "addupper":
            keymap[keycode][''] = keysym
            keymap[keycode]['shift'] = keysym.upper()
            continue

        if modifiers[0] in MODIFIERS:
            keymap[keycode][modifiers[0]] = keysym
            continue
        else:
            keymap[keycode][''] = keysym
            continue
        
    for i in includes:
        print 'include', i
    for i in sorted(keymap.keys()):
        output = []

        if keymap[i]['']:
            output.append(keymap[i][''])
        
        for m in MODIFIERS:
            if m in keymap[i]:
                output.append('%s : %s' % (m, keymap[i][m]))
        print 'keycode %3d =' % i, ', '.join(output)

if __name__ == "__main__":
    main()
