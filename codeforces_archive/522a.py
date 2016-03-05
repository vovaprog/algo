#!/usr/bin/python3

def read_int():
    return int(input().split()[0])
    
def walk_tree(cur, parent, depth, maxDepth):
    depth += 1
    if depth>maxDepth: maxDepth = depth
    for child in rs[cur]:
        if child != parent:
            result = walk_tree(child,cur,depth,maxDepth)
            if result > maxDepth: maxDepth = result
    return maxDepth    
    
rs = {}    
    
nReposts = read_int()

readRoot = True
rootPoster = None

for i in range(0,nReposts):
    words = input().split()
    words[0] = words[0].lower()
    words[2] = words[2].lower()
    if readRoot:
        readRoot = False
        rootPoster = words[2]
    if not words[0] in rs: rs[words[0]] = []
    if not words[2] in rs: rs[words[2]] = []
    rs[words[0]].append(words[2])
    rs[words[2]].append(words[0])
    
maxDepth = walk_tree(rootPoster,rootPoster,0,0)    
    
print(maxDepth)    
    
