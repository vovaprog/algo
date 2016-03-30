#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int n, a, b;
    
    scanf("%d %d %d", &n, &a, &b);
    
    int v = n * 200;
    
    int result = (v + a + b) % n;

    if(result==0) result = n;
    
    printf("%d\n",result);
    
    return 0;
}
