#!/usr/bin/python3
""" doc """

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    N = eval(sys.argv[1])
except Exception:
    print("N must be a number")
    exit(1)
if (N < 4):
    print('N must be at least 4')
    exit(1)

board = [[0]*N for _ in range(N)]


def is_attack(i, j):
    """ doc """
    for k in range(0, N):
        if board[i][k] == 1 or board[k][j] == 1:
            return True
    for k in range(0, N):
        for z in range(0, N):
            if (k + z == i + j) or (k - z == i - j):
                if board[k][z] == 1:
                    return True
    return False


def N_queen(n):
    """ doc """
    if n == 0:
        return True
    for i in range(0, N):
        for j in range(0, N):
            if (not(is_attack(i, j))) and (board[i][j] != 1):
                board[i][j] = 1
                if N_queen(n - 1) is True:
                    return True
                board[i][j] = 0

    return False


def boardReset(N):
    """ doc """
    for k in range(N):
        for z in range(N):
            board[k][z] = 0


def validate(board, N):
    """ doc """
    suma = 0
    store = []
    for k, i in enumerate(board):
        if 1 in i:
            store.append([k, i.index(1)])
            suma += 1
    if suma == N:
        return store
    else:
        return []


def control(N):
    """ doc """
    for i in range(N):
        board[0][i] = 1
        N_queen(N - 1)
        solution = validate(board, N)
        if len(solution) == N:
            print(solution)
        boardReset(N)


control(N)
