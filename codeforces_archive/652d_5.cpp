#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> Tree;

struct Segment{
    int b,e;
    int count=0;
};

Segment ss[200010];
int ssInd[200010];

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
    
    Tree begs;

    for(int i=0;i<n;++i)
    {
        Segment& s = ss[ssInd[i]];

        s.count = begs.order_of_key(s.b);

        begs.insert(s.b);
    }

    for(int i=0;i<n;++i)
    {
        printf("%d\n",ss[i].count);
    }
    
    return 0;
}


