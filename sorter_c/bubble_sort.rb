
def timeDifMillis(start, finish)
   (finish - start) * 1000.0
end

def bubbleSort list
    for i in (list.size-1).downto(2)
        for j in 0..(i-1)
            if list[j]>list[j+1]
                temp=list[j]
                list[j]=list[j+1]
                list[j+1]=temp
            end
        end
    end
end

list = Array.new

for i in 0...10000
	list.push(rand(100))
end

print list
puts

millis = Time.now
bubbleSort(list)
millis= timeDifMillis(millis,Time.now)

print list
print "millis passed: "
puts millis