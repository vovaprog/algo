#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Segment{
    int b,e;
    int count=0;
};

Segment ss[200010];
int ssInd[200010];
int segEnds[200010];


//==================================================================================
// Fenwick Tree Sum
//==================================================================================

vector<int> fenwickT;
int fenwickN;

void fenwickInit (int nn)
{
    fenwickN = nn;
    fenwickT.assign(fenwickN, 0);
}

void fenwickInc (int i, int delta)
{
    for (; i < fenwickN; i = (i | (i+1)))
        fenwickT[i] += delta;
}

void fenwickInit (vector<int> a)
{
    fenwickInit ((int) a.size());
    for (unsigned i = 0; i < a.size(); i++)
        fenwickInc(i, a[i]);
}

int fenwickSum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += fenwickT[r];
    return result;
}

int fenwickSum (int l, int r)
{
    return fenwickSum(r) - fenwickSum(l-1);
}

//==================================================================================
// Fenwick Tree Sum
//==================================================================================


int main()
{
    int n;
    
    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
    {
        scanf("%d%d",&ss[i].b,&ss[i].e);
        ssInd[i] = i;
        segEnds[i] = ss[i].e;
    }

    sort(ssInd,ssInd+n,[](int x,int y)
        {
            Segment& s0 = ss[x];
            Segment& s1 = ss[y];

            return s0.b < s1.b;
        });
    sort(segEnds,segEnds+n);


    fenwickInit(n+10);

    for(int i=n-1;i>=0;--i)
    {
        Segment& s = ss[ssInd[i]];

        auto it = lower_bound(segEnds,segEnds+n,s.e);
        int ind = distance(segEnds, it);

        s.count = fenwickSum(ind - 1);

        fenwickInc(ind, 1);
    }

    for(int i=0;i<n;++i)
    {
        printf("%d\n",ss[i].count);
    }
    
    return 0;
}


