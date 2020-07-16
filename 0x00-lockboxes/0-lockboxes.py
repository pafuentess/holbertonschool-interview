#!/usr/bin/env python3
""" doc """


def canUnlockAll(boxes):
    """ doc """
    keys = boxes[0]
    open_box = []
    for i in range(1, len(boxes)):
        if i in keys:
            for j in range(0, len(boxes[i])):
                if boxes[i][j] == i and boxes[i][j] not in keys:
                    keys.append(boxes[i][j])
                else:
                    if boxes[i][j] not in keys:
                        keys.append(boxes[i][j])
    last = keys[len(keys) - 1]
    for last_keys in boxes[last]:
        if last_keys not in keys:
            keys.append(last_keys)
    if 0 in keys:
        if len(keys) == len(boxes):
            return True
        else:
            return False
    else:
        if (len(keys) + 1 == len(boxes)):
            return (True)
        else:
            return (False)
