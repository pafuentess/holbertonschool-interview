#!/usr/bin/python3
""" doc """


def check_initial_keys(boxes, keys):
    for key in keys:
        if key > len(boxes):
            keys.remove(key)
    return keys


def canUnlockAll(boxes):
    """ doc """
    if boxes == [] or len(boxes) == 1:
        return True
    if len(boxes[0]) == 0:
        return False
    keys = boxes[0]
    keys.append(0)
    update_keys = check_initial_keys(boxes, keys)
    for i in keys:
        if i < len(boxes):
            for j in boxes[i]:
                if j not in keys and j < len(boxes):
                    keys.append(j)
    if len(keys) == len(boxes):
        return True
    else:
        return (False)
