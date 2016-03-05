#!/usr/bin/python3

def read_ints():
    return list(map(int, input().split()))
    
(nRows,nCols,nRqs) = read_ints()

rowTasks = {}
colTasks = {}

for i in range(nRqs):
    task = {}
    (task["op"],task["ind"],task["clr"]) = read_ints()
    task["ind"] -= 1
    task["number"] = i
    if task["op"]==1:
        rowTasks[task["ind"]] = task
    else:
        colTasks[task["ind"]] = task

for i in range(nRows):
    for j in range(nCols):
        clr = 0
        rowTask = None
        if i in rowTasks:
            rowTask = rowTasks[i]
            clr = rowTask["clr"]
        if j in colTasks:
            colTask = colTasks[j]
            if rowTask==None or colTask["number"] > rowTask["number"]:
                clr = colTask["clr"]
        print(str(clr),end=" ")
    print("")        
    
