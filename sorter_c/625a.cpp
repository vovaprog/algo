#include <iostream>

using namespace std;

typedef long long int int64;

int main()
{    
    int64 totalMoney;
    int64 costPlastic;
    int64 costGlass;
    int64 costGlassReturn;
    
    cin >>totalMoney>>costPlastic>>costGlass>>costGlassReturn;
    
    int64 costGlassWithRet = costGlass - costGlassReturn;
    
    if( totalMoney < costPlastic && totalMoney < costGlass)
    {
        cout <<0;       
    }
    else
    {
        if(costPlastic <= costGlassWithRet || costGlass > totalMoney)
        {
            cout << (totalMoney / costPlastic);
        }
        else
        {
            int64 result = 0;
            
            if(costGlass<=totalMoney) 
            {
                result+=1;
            }
            
            int64 v1 = (totalMoney - costGlass) / costGlassWithRet;
            int64 v2 = (totalMoney - costGlass) % costGlassWithRet;
            int64 v3 = v2 + costGlassReturn;
            
            if(v3>=costGlass)
            {
                result += 1;
                v3 -= costGlassWithRet;  
            }
            
            result += v3 / costPlastic;
            
            result += v1;
            
            cout << result;
        }
    }
}

