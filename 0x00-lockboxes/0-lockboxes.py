#!/usr/bin/python3
""" doc """


def canUnlockAll(boxes):
    """ doc """
    keys = boxes[0]
    keys.append(0)
    for i in keys:
        for j in boxes[i]:
            index = boxes.index(boxes[i])
            if index == j and j not in keys:
                keys.append(j)
            else:
                if j not in keys:
                    keys.append(j)
    if len(keys) == len(boxes):
        return True
    else:
        return (False)
