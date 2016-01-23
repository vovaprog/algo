import random

limit = 10000

print str(limit)+" "+str(limit*2)

for i in range(0,limit * 2):
    v1=random.randint(1,1000)
    while True:
        v2=random.randint(1,1000)
        if v2!=v1: break
    
    print str(v1)+" "+str(v2)

