#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int n;
    
    scanf("%d",&n);
    
    int result, prevR = 0;
    
    for(int i = 0; i < n; ++i)
    {
        int r;
        scanf("%d",&r);
        
        if(r - prevR > 15)
        {
            result = prevR + 15;
            printf("%d\n",result);
            return 0;
        }
        
        prevR = r;
    }
    
    result = min(prevR + 15, 90);
    
    printf("%d\n", result);
    
    return 0;
}
