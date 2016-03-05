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
    int start, end, dist, index;
    Pair(int start, int end): start(start), end(end), dist(end-start)
    {}
    Pair()
    {}
};

int comparePairs( const void* al0, const void* al1)
{
    return ((Pair*)al1)->start - ((Pair*)al0)->start;    
}

int main()
{
    int sz, nRequests;

    scanf("%d %d", &sz, &nRequests);

    unordered_map<int, int> m;
    vector<Pair> pairs;
    vector<Pair> rqs;
    pairs.reserve(sz);
    rqs.reserve(sz);
    
    int val;
    
    for (int i = 0;i < sz;i++)
    {
    	int b;
    	
        scanf("%d", &b);
        
        if (tryGetValue(m, b, val))
        {
            pairs.emplace_back(val, i);
        }        
        m[b] = i;        
    }
      
    for(int q=0;q<nRequests;q++)
    {
        int rqStart,rqEnd;
        
        scanf("%d %d",&rqStart, &rqEnd);
        --rqStart;
        --rqEnd;    
        
        rqs.emplace_back(rqStart,rqEnd);
        rqs[q].dist=2000000000;
        rqs[q].index = q;
    }
    
    sort(rqs.begin(),rqs.end(),[](const Pair &p0,const Pair &p1)
    	{
    		//return p0.end < p1.end;
    		return p0.start < p1.start;
    	});
    	
    //qsort( rqs.data(), nRequests, sizeof(Pair), comparePairs );	
    	    
    int curStart = 0;
    
    for(auto& p : pairs)
    {    	
    	for(int i=curStart;rqs[i].start<=p.start && i<nRequests;i++)
    	{
    		if(rqs[i].dist!=1 && rqs[i].end>=p.end && p.dist < rqs[i].dist)
    		{
    			rqs[i].dist = p.dist;
    		}
    	}
    }
    
    int buf[500000];
    
    for(auto &rq : rqs)
    {
    	buf[rq.index] = rq.dist == 2000000000?-1:rq.dist;	
    }
    
    for(int i=0;i<nRequests;i++)
    {
    	printf("%d\n",buf[i]);	
    }

    return 0;
}