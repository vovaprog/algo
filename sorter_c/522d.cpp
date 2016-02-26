#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

template <class TMap, class TKey, class TValue>
inline bool tryGetValue(TMap &m, TKey &key, TValue &u)
{
    auto it = m.find(key);
    if (it != m.end())
    {
        u = it->second;
        return true;
    }
    return false;
}

struct Pair
{
    int start, end, dist;
    Pair(int start, int end): start(start), end(end), dist(end-start)
    {}
    Pair()
    {}
};

int main()
{
    int sz, nRequests;
    int buf[100000];

    scanf("%d %d", &sz, &nRequests);

    for (int i = 0;i < sz;i++)
    {
        scanf("%d", &buf[i]);
    }

    unordered_map<int, int> m;
    vector<Pair> pairs;
    pairs.reserve(sz);
    
    int val;
    int prevPairs[100000];
    int prevPair = -1;
    
    for (int i = 0;i < sz;i++)
    {
        if (tryGetValue(m, buf[i], val))
        {
            pairs.emplace_back(val, i);
            prevPair = pairs.size() - 1;
        }        
        m[buf[i]] = i;
        prevPairs[i] = prevPair;
    }
   
    for(int q=0;q<nRequests;q++)
    {
        int rqStart,rqEnd;
        
        scanf("%d %d",&rqStart, &rqEnd);
        --rqStart;
        --rqEnd;        
        
        int minDist = 2000000000;
        
        int p = prevPairs[rqEnd];
        
        for(;p>=0 && pairs[p].end>rqStart;--p)
        {
            if(pairs[p].start>=rqStart)
            {
                minDist = min(minDist,pairs[p].dist);
                if(minDist==1)
                {
                    break;
                }
            }            
        }        
        
        if(minDist==2000000000)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",minDist);
        }        
    }

    return 0;
}