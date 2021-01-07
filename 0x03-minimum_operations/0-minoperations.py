#!/usr/bin/python3

'''
a method that calculates the fewest number of operations needed
to result in exactly n H characters in the file
'''


def minOperations(n):
    '''
    min operations
    '''
    count = 0
    i = 2
    while n > 1:
        while n % i == 0:
            count = count + i
            n = n // i
        i = i + 1
    return count
