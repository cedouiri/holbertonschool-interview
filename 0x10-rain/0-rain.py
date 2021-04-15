#!/usr/bin/python3
'''
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains

'''


def rain(walls: list) -> int:
    '''
    Return: Integer indicating total amount of rainwater retained
    '''
    beg, end, mx, rain, edges, n = 0, 0, 0, 0, [], len(walls)
    end = beg + 1
    mx = end
    while end < n:
        while end < n and walls[beg] > walls[end]:
            end += 1
            if end < n and walls[mx] <= walls[end]:
                mx = end
        end = mx
        if end > beg + 1:
            edges.append((beg, end))
        beg = end
        end = beg + 1
        mx = end
    for t in edges:
        t0 = t[0]
        t1 = t[1]
        holding_wall = min(walls[t0], walls[t1])
        for i in walls[t0 + 1: t1]:
            rain += holding_wall - i

    return rain
