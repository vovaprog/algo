#!/usr/bin/python3

def read_ints():
    return list(map(int, input().split()))
    
flashCount = read_ints()[0]
fileSize = read_ints()[0]

flashes = []

for i in range(0,flashCount):
    flashes.append(read_ints()[0])
    
flashes = sorted(flashes,reverse = True)

sizeOnFlashes = 0
counter = 0

for i in flashes:
    sizeOnFlashes += i
    counter += 1
    if sizeOnFlashes>=fileSize:
        break

print(counter)

