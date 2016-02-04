import random

mul = 3
base = 1000
limit = mul * base

print str(limit)+" "+str(limit)
counter = 0

for i in range(0,mul):    
    for j in range(i*base,i*base+base):        
        print str(i+1)+" "+str(j+1)+" "+str(random.randint(1,100))
        counter += 1

print counter

