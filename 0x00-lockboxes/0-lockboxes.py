#!/usr/bin/python3
""" doc """


def check_all_boxes(boxes, keys):
    for box in boxes:
        for key in box:
            if key == box.index and key not in keys:
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
        for j in boxes[i]:
            index = boxes.index(boxes[i])
            if index == j and j not in update_keys:
                keys.append(j)
            else:
                if j not in keys:
                    update_keys.append(j)
    if len(update_keys) == len(boxes):
        return True
    else:
        return (False)
