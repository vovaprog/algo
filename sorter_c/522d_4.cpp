#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

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

//================================================================
//===================== segment tree (min) =======================
//================================================================

#define INF 2000000000

int *t;
int treeSize;

void segmentTreeInit(int size)
{
    treeSize = size;
    
    int tSize = size * 4;
    
    t = new int[tSize];
    
    for(int i=0;i<tSize;i++)
    {
        t[i] = INF;
    }
}

int _segmentTreeFind(int v, int tl, int tr, int l, int r) 
{
	if (l > r)
	{
		return INF;
	}
	if (l == tl && r == tr)
	{
		return t[v];
	}
	
	int tm = (tl + tr) / 2;
	
	return min(
	    _segmentTreeFind (v*2, tl, tm, l, min(r,tm)),
		_segmentTreeFind (v*2+1, tm+1, tr, max(l,tm+1), r)
		);
}

int segmentTreeFind(int l, int r)
{
    return _segmentTreeFind(1,0,treeSize-1,l,r);
}

void _segmentTreeUpdate(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
	{
		t[v] = new_val;
	}
	else 
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			_segmentTreeUpdate (v*2, tl, tm, pos, new_val);
		else
			_segmentTreeUpdate (v*2+1, tm+1, tr, pos, new_val);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

void segmentTreeUpdate(int pos, int newVal)
{
    _segmentTreeUpdate(1,0,treeSize-1,pos,newVal);
}

void segmentTreePrint()
{
	printf("[[[   ");
	for(int i=0;i<treeSize * 4;i++)
	{	
	    if(t[i]==INF) printf("INF ");
	    else printf("%d ",t[i]);
	}
	printf("]]]\n");
}

//================================================================
//===================== segment tree (min) =======================
//================================================================


int buf[500000];
int bufStarts[500000];

int main()
{    
    int nRequests, sz;

    scanf("%d %d", &sz, &nRequests);
    
    segmentTreeInit(sz);

    //-------------------------------------
    
    unordered_map<int, int> m;
    int val;
    
    for (int i = 0;i < sz;i++)
    {
    	int b;
    	
        scanf("%d", &b);
        
        if (tryGetValue(m, b, val))
        {
            buf[i] = i-val;
            bufStarts[val] = i-val; 
            segmentTreeUpdate(i,i-val);
        }        
        else
        {
            buf[i] = INF;            
        }
        bufStarts[i] = INF;
        
        m[b] = i;   
    }

    //-------------------------------------
    
    vector<Pair> rqs;
    rqs.reserve(nRequests);    
        
    for(int q=0;q<nRequests;q++)
    {
        int rqStart,rqEnd;
        
        scanf("%d %d",&rqStart, &rqEnd);
        --rqStart;
        --rqEnd;    
        
        rqs.emplace_back(rqStart,rqEnd,q);
    }    
    	
    qsort(rqs.data(),nRequests,sizeof(Pair),comparePairs);
    	
    //-------------------------------------
    
    int lastClear = 0;
    
    for(auto &rq : rqs)
    {
    	for(int i=lastClear;i<rq.start;i++)
    	{    		
    		if(bufStarts[i]!=INF) 
    		{
    			segmentTreeUpdate(i + bufStarts[i],INF);
    		}
    	}
    	lastClear = rq.start;
    	
    	rq.minDist = segmentTreeFind(rq.start,rq.end);     	
    }
    
    //-------------------------------------
    
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