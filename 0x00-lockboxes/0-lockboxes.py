#!/usr/bin/python3
""" doc """


def check_initial_keys(boxes, keys):
    k_temp = []
    for i in range(len(keys)):
        if keys[i] <= len(boxes) and keys[i] not in k_temp:
            k_temp.append(keys[i])
    print(k_temp)
    return (k_temp)


def canUnlockAll(boxes):
    """ doc """
    if boxes == [] or len(boxes) == 1:
        return True
    if len(boxes[0]) == 0:
        return False
    keys = boxes[0]
    keys.append(0)
    updated_keys = check_initial_keys(boxes, keys)
    for i in updated_keys:
        if i < len(boxes):
            for j in boxes[i]:
                if j not in updated_keys and j < len(boxes):
                    updated_keys.append(j)
    print(updated_keys)
    if len(updated_keys) == len(boxes):
        return True
    else:
        return (False)
