#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int64 n;
    
    cin >> n;
    
    int64 d = n / 3;
    int64 rem = n % 3;
    
    int64 result = d * 2;
    
    if(rem!=0)
    {
        ++result;
    }

    cout << result;
    
    return 0;
}
