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
    int start, end, index, minDist;
    /*Pair(int start, int end): start(start), end(end), minDist(2000000000)
    {}*/
    Pair(int start, int end, int index): start(start), end(end), index(index), minDist(2000000000)
    {}    
    Pair(): minDist(2000000000)
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
    
    int buf[500000];
    
    for (int i = 0;i < sz;i++)
    {
    	int b;
    	
        scanf("%d", &b);
        
        if (tryGetValue(m, b, val))
        {
            buf[i] = i - val;
        }        
        else
        {
            buf[i] = 0;
        }
        m[b] = i;    
        //printf("[%d]   ",buf[i]);
    }
    //printf("\n");  
    
    for(int q=0;q<nRequests;q++)
    {
        int rqStart,rqEnd;
        
        scanf("%d %d",&rqStart, &rqEnd);
        --rqStart;
        --rqEnd;    
        
        rqs.emplace_back(rqStart,rqEnd,q);
    }
    
    sort(rqs.begin(),rqs.end(),[](const Pair &p0,const Pair &p1)
    	{
    		//return p0.end < p1.end;
    		return p0.start < p1.start;
    	});
    	
    int rqsHead = 0;
    vector<int> curRqs;
    
    for(int i=0;i<sz;i++)
    {
        //printf("--------- %d -----------\n",i);
        
        while(rqsHead<rqs.size() && rqs[rqsHead].start==i)
        {
            curRqs.push_back(rqsHead++);           
            debug("%d",rqsHead);
        }                
        
        if(curRqs.size()==0 && rqsHead>=rqs.size()) break;
        
        debug("%d",buf[i]);
        
        if(buf[i]>0)
        {
            for(int j = curRqs.size()-1;j>=0;--j)
            {
                debug("%d %d %d",j,rqs[curRqs[j]].start,i);
                
                if(i>rqs[curRqs[j]].end)
                {
                    debug("--erase %d",j);
                    curRqs.erase(curRqs.begin()+j);
                }
                else if(rqs[curRqs[j]].minDist>buf[i] && i-buf[i]>=rqs[curRqs[j]].start)
                {   
                    debug("min %d",j);
                    rqs[curRqs[j]].minDist = buf[i];
                }                
            }
        }        
    }
    
    //qsort( rqs.data(), nRequests, sizeof(Pair), comparePairs );	
    	        
    
    
    for(auto &rq : rqs)
    {
    	buf[rq.index] = rq.minDist == 2000000000?-1:rq.minDist;	
    }
    
    for(int i=0;i<nRequests;i++)
    {
    	printf("%d\n",buf[i]);	
    }

    return 0;
}