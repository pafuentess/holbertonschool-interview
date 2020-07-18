#!/usr/bin/python3
""" doc """


def check_all_boxes(boxes, keys):
    for box in boxes:
        for key in box:
            if key == box.index and key not in keys and key < len(boxes):
                keys.append(key)
    return keys


def canUnlockAll(boxes):
    """ doc """
    if boxes == [] or len(boxes) == 1:
        return True
    if len(boxes[0]) == 0:
        return False
    keys = boxes[0]
    keys.append(0)
    update_keys = check_all_boxes(boxes, keys)
    for i in keys:
        if i < len(boxes):
            for j in boxes[i]:
                if j not in keys and j < len(boxes):
                    update_keys.append(j)
    if len(update_keys) == len(boxes):
        return True
    else:
        return (False)
