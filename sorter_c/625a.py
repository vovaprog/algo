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
    if costPlastic <= costGlassWithRet:
        print(int(totalMoney / costPlastic))
    else:
        if costGlassWithRet == 1:
            print(totalMoney - costGlass + int(costGlass / min(costGlass,costPlastic)))
        else:
            if int((totalMoney - costGlass) / costGlassWithRet) > 0:
                print(int((totalMoney - costGlass) / costGlassWithRet) + int((costGlass + costGlassReturn) / min(costGlass,costPlastic)))
            else:
                print(int((totalMoney - costGlass + costGlassWithRet) / min(costGlass,costPlastic)) + 1)