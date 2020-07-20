#!/usr/bin/python3
""" doc """


def canUnlockAll(boxes):
    """ doc """
    if len(boxes) == 1:
        return True
    status = []
    for i in boxes:
        status.append(0)
    status[0] = 1
    keys = boxes[0]
    seek = True
    for i in keys:
        if i < len(boxes):
            if status[i] == 0:
                status[i] = 1
                for j in (boxes[i]):
                    if j not in keys:
                        keys.append(j)
    if 0 in status:
        return (False)
    else:
        return (True)
