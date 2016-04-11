#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Segment{
    int b,e;
    int count=0;
    bool operator<(const Segment &s) const
    {
        if(b==s.b)
        {
            return e > s.e;
        }
        else
        {
            return b < s.b;
        }
    }
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
        ssInd[i]=i;
    }
    
    sort(ssInd,ssInd+n,[](int x,int y)
        {
            Segment& s0 = ss[x];
            Segment& s1 = ss[y];

            if(s0.b==s1.b)
            {
                return s0.e > s1.e;
            }
            else
            {
                return s0.b < s1.b;
            }
        });
    
    list<int> q;

    for(int i=0;i<n;++i)
    {
        Segment &s = ss[ssInd[i]];

        for(auto it = q.begin();it!=q.end();)
        {
            Segment& t = ss[*it];

            if(t.e<=s.b)
            {
                it = q.erase(it);
            }
            else
            {
                if(t.e >= s.e)
                {
                    ++t.count;
                }
                ++it;
            }
        }
        q.push_back(ssInd[i]);
    }

    for(int i=0;i<n;++i)
    {
        printf("%d\n",ss[i].count);
    }
    
    return 0;
}
