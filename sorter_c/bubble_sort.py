from random import randint
import time

get_millis = lambda: int(round(time.time() * 1000))

def bubbleSort(list):
	for i in reversed(range(1,len(list))):
		for j in range(i):
			if list[j]>list[j+1]:
				temp=list[j+1]
				list[j+1]=list[j]
				list[j]=temp
	return list				

list =[]

for i in range(10000):
	list.append(randint(0,100))

print list

millis=get_millis()
list=bubbleSort(list)
millis=get_millis()-millis

print list

print "millis: "+str(millis)
