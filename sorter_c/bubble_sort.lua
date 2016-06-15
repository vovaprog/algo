--local socket = require "socket"
--function  getMillis() return socket.gettime() * 1000 end

function  getMillis() return os.clock() * 1000 end

function bubbleSort(list)
	for i = #list-1,1,-1 do
		for j=0, i-1 do
			if list[j]>list[j+1] then
				temp=list[j+1]
				list[j+1]=list[j]
				list[j]=temp
			end
		end
	end

	return list
end

function printList(list)
	for i=0, #list - 1 do
		io.write(list[i].." ")				
	end
	print()
end

list = {}

math.randomseed(os.time()); math.random(); math.random(); math.random()

for i = 0,10000 do
	list[i]=math.random(100)
end

printList(list)

millis = getMillis()
list = bubbleSort(list)
millis = getMillis() - millis

print("----------")
printList(list)

print("millis: "..millis)
