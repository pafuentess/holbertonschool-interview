#!/usr/bin/python3
""" doc """


def check_keys(boxes, keys):
    if len(boxes) == len(keys):
        return (0)
    else:
        return (1)


def canUnlockAll(boxes):
    """ doc """
    keys = boxes[0]
    keys.append(0)
    for i in range(1, len(boxes)):
        if i in keys:
            for j in range(0, len(boxes[i])):
                if boxes[i][j] == i and boxes[i][j] not in keys:
                    keys.append(boxes[i][j])
                else:
                    if boxes[i][j] not in keys:
                        keys.append(boxes[i][j])
    check = check_keys(boxes, keys)
    if check == 0:
        return True
    else:
        return False
