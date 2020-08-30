#!/usr/bin/python3

import sys

split = []
file_size = 0
status = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for i, line in enumerate(sys.stdin, 1):
        split = line.split(" ")
        store = split[-2:]
        if store < 2:
            continue
        if store[0] in status:
            status[store[0]] = status[store[0]] + 1
            file_size = file_size + int(store[1])
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for key in sorted(status.keys()):
                if status[key] != 0:
                    print("{}: {}".format(key, status[key]))
finally:
    print("File size: {}".format(file_size))
    for key in sorted(status.keys()):
        if status[key] != 0:
            print("{}: {}".format(key, status[key]))
