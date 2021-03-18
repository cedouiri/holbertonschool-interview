#!/usr/bin/python3
'''
N Queens
'''


import sys


def verify(a, b):
    '''
    nqueens
    '''
    if a[0] == b[0] or a[1] == b[1]:
        return True

    rx = abs(a[0] - b[0])
    ry = abs(a[1] - b[1])

    r = min(rx, ry)

    if r == 0:
        return False

    if a[0] > b[0]:
        if a[1] > b[1]:
            x = [a[0] - r, a[1] - r]
            if x == b:
                return True
        else:
            x = [a[0] - r, a[1] + r]
            if x == b:
                return True
    if b[0] > a[0]:
        if b[1] > a[1]:
            x = [b[0] - r, b[1] - r]
            if x == a:
                return True
        else:
            x = [b[0] - r, b[1] + r]
            if x == a:
                return True
    return False


def do_queens(arr):
    '''
    nqueens
    '''
    ln = len(arr)
    for i in range(ln - 1):
        c = arr[i]
        for j in range(i + 1, ln):
            if verify(c, arr[j]):
                return True
    return False


def generate(arr, line_index, num, possible_sol, new_arr=[]):
    '''
    nqueens
    '''
    for i in arr[line_index]:
        n_a = new_arr[:]
        if do_queens(n_a + [i]) is False:
            n_a.append(i)
            if line_index + 1 == num:
                possible_sol.append(n_a)
            else:
                generate(arr, line_index + 1, num, possible_sol, n_a)


def nqueen(num):
    '''
    nqueens
    '''
    possible_sol = []
    lines = []

    for i in range(num):
        current_list = []
        for j in range(num):
            a = [i, j]
            if a not in lines:
                current_list.append(a)
        lines.append(current_list)

    generate(lines, 0, num, possible_sol)

    return possible_sol


def main():
    if len(sys.argv) != 2:
        print('Usage: nqueen N')
        exit(1)
    elif not sys.argv[1].isdigit():
        print('N must be a number')
        exit(1)
    elif int(sys.argv[1]) < 4:
        print('N must be at least 4')
        exit(1)
    num = int(sys.argv[1])
    possible_sol = nqueen(num)
    for ps in possible_sol:
        print(ps)


main()
