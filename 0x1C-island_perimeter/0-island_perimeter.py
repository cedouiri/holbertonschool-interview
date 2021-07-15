#!/usr/bin/python3
'''

Module containing the island_perimeter function.
'''


def island_perimeter(grid):
    '''
    a function that returns the perimeter of the island described in grid:
    grid is a list of list of integers:
    **0 represents water
    **1 represents land
    **Each cell is square, with a side length of 1
    **Cells are connected horizontally/vertically (not diagonally).
    **grid is rectangular, with its width and height not exceeding 100
    '''
    p = 0
    n_rows = len(grid)
    for row in range(n_rows):
        r = grid[row]
        for col in range(len(r)):
            top = bottom = right = left = 0
            sides = 0
            c = r[col]
            if (c == 1):
                if row == 0:
                    sides += 1
                elif row - 1 >= 0:
                    top = grid[row - 1][col]
                    if (top == 0):
                        sides += 1
                if col == 0:
                    sides += 1
                elif col - 1 >= 0:
                    left = grid[row][col - 1]
                    if (left == 0):
                        sides += 1
                if col + 1 == len(r):
                    sides += 1
                elif col + 1 < len(r):
                    right = grid[row][col + 1]
                    if (right == 0):
                        sides += 1
                if row + 1 == n_rows:
                    sides += 1
                elif row + 1 < n_rows:
                    bottom = grid[row + 1][col]
                    if (bottom == 0):
                        sides += 1
                p += sides
    return p
