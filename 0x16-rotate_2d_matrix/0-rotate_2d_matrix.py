#!/usr/bin/python3
""" doc """


def rotate_2d_matrix(matrix):
    """ doc """
    matrix.reverse()
    tmp = [row.copy() for row in matrix]

    for i, row in enumerate(tmp):
        for j, n in enumerate(row):
            matrix[j][i] = tmp[i][j]
