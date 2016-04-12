#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Segment{
    int b,e;
    int count=0;
};

Segment ss[100010];
int ssInd[100010];

int main()
{
    int n;
    
    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",&ss[i].b,&ss[i].e);
        ssInd[i] = i;
    }

    sort(ssInd,ssInd+n,[](int x,int y)
        {
            Segment& s0 = ss[x];
            Segment& s1 = ss[y];

            return s0.e < s1.e;
        });
    
    set<int> begs;

    for(int i=0;i<n;++i)
    {
        Segment& s = ss[ssInd[i]];

        auto it = begs.lower_bound(s.b);

        s.count = distance(it, begs.end());

        begs.insert(s.b);
    }

    for(int i=0;i<n;++i)
    {
        printf("%d\n",ss[i].count);
    }
    
    return 0;
}


