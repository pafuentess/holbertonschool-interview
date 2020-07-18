#!/usr/bin/python3
""" doc """


def canUnlockAll(boxes):
    """ doc """
    keys = boxes[0]
    for i in keys:
        for j in boxes[i]:
            index = boxes.index(boxes[i])
            if index == j and j not in keys and j != 0:
                keys.append(j)
            else:
                if j not in keys and j != 0:
                    keys.append(j)
    if len(keys) == len(boxes) - 1:
        return True
    else:
        return (False)