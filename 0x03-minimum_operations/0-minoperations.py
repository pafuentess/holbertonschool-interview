#!/usr/bin/python3
""" doc """


def minOperations(n):
    """ doc """
    if type(n) is int and n > 0:
        x = 1
        op = 1
        store_x = 1
        while x < n:
            if n % x == 0 and x != store_x:
                store_x = x
                op = op + 1
            x = x + store_x
            op = op + 1
        if x == n:
            return op
    else:
        return 0
