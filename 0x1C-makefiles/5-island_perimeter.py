#!/usr/bin/python3
"""
    A module containing the island_perimeter calculator function
"""


def island_perimeter(grid):
    """
        A function that returns the perimeter of an island
        gride: is a list of integers
        0 = water zone
        1 = land zone
        one cell has square side of 1 unit
    """
    perim = 0
    num_rows = len(grid)
    num_col = len(grid[0])

    for i in range(num_rows):
        for j in range(num_col):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    perim += 1
                if (i + 1) == num_rows or grid[i + 1][j] == 0:
                    perim += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perim += 1
                if (j + 1) == num_col or grid[i][j + 1] == 0:
                    perim += 1
    return perim
