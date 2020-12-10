#!/usr/bin/python3
def canUnlockAll(boxes):
    '''
    a method that determines if all the boxes can be opened
    '''
    for key in range(1, len(boxes) - 1):
        ctr = False
        for i in range(len(boxes)):
            c = (key in boxes[i] and key != i)
            if c:
                break
        if c is False:
            return c
    return True
