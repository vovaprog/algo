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
            #print("C");
            #print(int(costGlassReturn / costPlastic))
            if costGlassReturn >= costPlastic:
                print(totalMoney - costGlass + 1 + int(costGlassReturn / costPlastic))
            else:
                print(totalMoney - costGlass + 1)
        else:
            if int((totalMoney - costGlass) / costGlassWithRet) > 0:
                #print ("A")
                #print(int((totalMoney - costGlass) / costGlassWithRet))
                #print(int((costGlass) / min(costGlass,costPlastic)))
                print(int((totalMoney - costGlass) / costGlassWithRet) + int((costGlass) / min(costGlass,costPlastic)) + int(costGlassReturn / costPlastic))
            else:
                #print ("B")
                print(int((totalMoney - costGlass + costGlassWithRet) / min(costGlass,costPlastic)) + 1)