#!/usr/bin/python3
""" doc """


def rain(walls):
    """ doc """

    n = len(walls)

    if n == 0:
        return 0

    water = 0

    left = [0] * n
    left[0] = walls[0]
    right = [0] * n
    right[-1] = walls[-1]

    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    for i in range(n):
        water += min(left[i], right[i]) - walls[i]

    return water
