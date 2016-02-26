

def fact(x):
    result=x;
    for i in range(x-1,1,-1):
        result *= i
    return result

prevValue = 1

for i in range(1,170):
    s1 = str(fact(i))
    s2 = s1.strip('0')
    zeros = len(s1) - len(s2)    
    print("fact("+str(i)+")="+str(fact(i))+"   zeros="+str(zeros))
    #print("fact("+str(i)+")="+str(fact(i)))
    
    #if zeros!=prevValue and zeros!=prevValue+1 and zeros!=prevValue+2:
     #   print("i="+str(i)+"   zeros="+str(zeros)+"   prevZeros="+str(prevValue))
    #prevValue = zeros


