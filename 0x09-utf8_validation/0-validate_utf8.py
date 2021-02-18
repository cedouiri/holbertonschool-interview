#!/usr/bin/python3
"""
UTF-8 Validator Module
"""


def validUTF8(data):
    Nbytes = 0
    for i in data:
        bin = format(i, '#010b')[-8:]
        if Nbytes == 0:
            for b in bin:
                if b == "0":
                    break
                Nbytes += 1

            if Nbytes == 0:
                continue

            if Nbytes > 4 or Nbytes == 1:
                return False
        else:
            if bin[0] != "1" or bin[1] != "0":
                return False

        Nbytes -= 1

    return Nbytes == 0
