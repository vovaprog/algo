#!/usr/bin/python3

def read_int():
    return int(input().split()[0])

totalMoney = read_int()
costPlastic = read_int()
costGlass = read_int()
costGlassReturn = read_int()

costGlassWithRet = costGlass - costGlassReturn

if totalMoney < costPlastic and totalMoney < costGlass:
    print(0)       
else:
    if costPlastic <= costGlassWithRet or costGlass > totalMoney:
        print(totalMoney // costPlastic)
    else:
        result = 0
        
        if costGlass<=totalMoney: 
            result+=1
        
        v1 = (totalMoney - costGlass) // costGlassWithRet
        v2 = (totalMoney - costGlass) % costGlassWithRet
        v3 = v2 + costGlassReturn;
        
        if v3>=costGlass:
            result += 1
            v3 -= costGlassWithRet  
        
        result += v3 // costPlastic
        
        result += v1;
        
        print(result)
