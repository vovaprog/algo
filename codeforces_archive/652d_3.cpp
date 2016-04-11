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

struct SetCompareBegin {
    bool operator() (const int x, const int y) const{
        Segment& s0 = ss[x];
        Segment& s1 = ss[y];

        return s0.b > s1.b;
    }
};

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
    
    set<int,SetCompareBegin> begs;

    for(int i=n-1;i>=0;--i)
    {
        auto it = begs.lower_bound(ssInd[i]);

        for(;it!=begs.end();++it)
        {
            ss[*it].count++;
        }

        begs.insert(ssInd[i]);
    }

    for(int i=0;i<n;++i)
    {
        printf("%d\n",ss[i].count);
    }
    
    return 0;
}


