#!/usr/bin/python3

def read_int():
    return int(input())

n = read_int()

result = 0

for i in range(n,0,-1):
	result += (1<<i)

print(result)

