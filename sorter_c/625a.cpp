#include <iostream>

using namespace std;

int main()
{    
    long long int totalMoney;
    long long int costPlastic;
    long long int costGlass;
    long long int costGlassReturn;
    
    cin >>totalMoney>>costPlastic>>costGlass>>costGlassReturn;
    
    long long int costGlassWithRet = costGlass - costGlassReturn;
    
    if( totalMoney < costPlastic && totalMoney < costGlass)
    {
        cout <<0;       
    }
    else
    {
        if(costPlastic <= costGlassWithRet || costGlass > totalMoney)
        {
            cout <<((totalMoney / costPlastic));
        }
        else
        {
            if(costGlassWithRet == 1)
            {
                if(costGlassReturn >= costPlastic)
                {
                    cout <<(totalMoney - costGlass + 1 + costGlassReturn / costPlastic);
                }
                else
                {
                    cout <<(totalMoney - costGlass + 1);
                }
            }
            else
            {
                if(((totalMoney - costGlass) / costGlassWithRet) > 0)
                {
                    cout << (totalMoney - costGlass)/costGlassWithRet + 1 + costGlassReturn / costPlastic;
                }
                else
                {
                    cout <<(((totalMoney - costGlass + costGlassWithRet) / min(costGlass,costPlastic)) + 1);
                }
            }
        }
    }
}