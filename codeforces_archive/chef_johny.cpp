#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int input[110];

int main()
{
    int n,nTests;
    
    scanf("%d",&nTests);
    
    for(int t=0;t<nTests;++t)
    {
        scanf("%d",&n);

        for(int i = 0; i < n; ++i)
        {
            int r;
            scanf("%d",&input[i]);
        }

        int k;
        scanf("%d",&k);
        --k;

        int v = input[k];

        int kCount=0;
        for(int i=0;i<k;++i)
        {
            if(input[i]==input[k]) ++kCount;
        }

        stable_sort(input,input+n);
        auto it = lower_bound(input,input+n,v);
        for(;kCount>0;--kCount) ++it;

        printf("%d\n",distance(input,it)+1);
    }    
    
    return 0;
}
