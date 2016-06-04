#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, result;

    cin >> a >> b;
    
    while(a!=0)
    {                      
        int div = a / b;
        int rem = a % b;

        result += a - rem;

        a = rem + div;
            
        if(a<b)
        {
            result += a;
            break;
        }
    }

    cout << result <<endl;
   
    return 0;
}
