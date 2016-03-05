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
    
    Pair(int start, int end, int index): start(start), end(end), index(index), minDist(2000000000)
    {}    
    Pair(): minDist(2000000000)
    {}
};

int comparePairs( const void* al0, const void* al1)
{
    return ((Pair*)al0)->start - ((Pair*)al1)->start;    
}

int buf[500000];

int main()
{
    int sz, nRequests;

    scanf("%d %d", &sz, &nRequests);

    unordered_map<int, int> m;
    vector<Pair> rqs;
    rqs.reserve(nRequests);
    
    int val;
    
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
    }

    
    for(int q=0;q<nRequests;q++)
    {
        int rqStart,rqEnd;
        
        scanf("%d %d",&rqStart, &rqEnd);
        --rqStart;
        --rqEnd;    
        
        rqs.emplace_back(rqStart,rqEnd,q);
    }
    
    /*sort(rqs.begin(),rqs.end(),[](const Pair &p0,const Pair &p1)
    	{
    		//return p0.end < p1.end;
    		return p0.start < p1.start;
    	});*/
    	
    qsort(rqs.data(),nRequests,sizeof(Pair),comparePairs);
    	
    int rqsHead = 0;
    list<int> curRqs;
    
    for(int i=0;i<sz;i++)
    {
        while(rqsHead<rqs.size() && rqs[rqsHead].start==i)
        {
            curRqs.push_back(rqsHead++);           
        }                
        
        if(curRqs.size()==0 && rqsHead>=rqs.size()) break;
        
        if(buf[i]>0)
        {
        	for(auto iter = curRqs.begin();iter!=curRqs.end();)
        	{
        		Pair &pr = rqs[*iter];
        		
        		if(i>pr.end)
                {
                    iter = curRqs.erase(iter);
                }
                else
                {
                	if(pr.minDist>buf[i] && i-buf[i]>=pr.start)
					{   
						pr.minDist = buf[i];
					}      		
					++iter;
				}
        	}
        }        
    }    
    
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