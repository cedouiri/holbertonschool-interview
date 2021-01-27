#!/usr/bin/python3
"""
    Computes stdin input
"""


import sys


def addFileSize(data):
    return int(data.split()[8])


def codes(data):
    return data.split()[7]

i = 0
s = 0
stat = {
    '200': 0, '301': 0, '400': 0, '401': 0,
    '403': 0, '404': 0, '405': 0, '500': 0
}

try:
    for line in sys.stdin:
        i += 1
        s += addFileSize(line)
        code = codes(line)
        if code in stat:
            stat[code] += 1
        if i == 10:
            print("File size: {:d}".format(s))
            for code, value in sorted(stat.items()):
                if value > 0:
                    print("{}: {:d}".format(code, value))
            i = 0
except Exception:
    pass

finally:
    print("File size: {:d}".format(s))
    for code, value in sorted(stat.items()):
        if value > 0:
            print("{}: {:d}".format(code, value))
    i = 0
