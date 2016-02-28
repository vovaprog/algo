#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

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

#define INF 2000000000
/*vector<int> t;
int n;

void init (int nn)
{
	n = nn;
	//t.assign (n, INF);
	t.reserve(n);
	for(int i=0;i<n;i++) 
	{
		//t[i] = INF;
		t.push_back(INF);
	}
}

int getmin (int r)
{
	int result = INF;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result = min (result, t[r]);
	return result;
}

void update (int i, int new_val)
{
	debug("update %d, %d",i,new_val);
	for (; i < n; i = (i | (i+1)))
	{
		t[i] = min (t[i], new_val);
		//debug("%d",t[i]);
	}
}*/

/*void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		update (i, a[i]);
}*/


int n, t[4*500000];

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		//t[v] = t[v*2] + t[v*2+1];
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

int sumT (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return min( sumT (v*2, tl, tm, l, min(r,tm)),
		 sumT (v*2+1, tm+1, tr, max(l,tm+1), r));		
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}

/*void printT()
{
	printf("[[[   ");
	//for(int i : t)
	for(int i=0;i<t.size();i++)
	{
		printf("%d ",t[i]);	
	}
	printf("]]]\n");
}*/

int main()
{
    int sz, nRequests;

    scanf("%d %d", &sz, &nRequests);

    unordered_map<int, int> m;
    vector<Pair> rqs;
    rqs.reserve(nRequests);
    
    int val;
    
    //init(sz);
    
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
            buf[i] = INF;
        }
        m[b] = i;   
        //update(i,buf[i]);
    }

    build(buf,1,0,sz-1);
    
//    printT();
    
    for(int q=0;q<nRequests;q++)
    {
        int rqStart,rqEnd;
        
        scanf("%d %d",&rqStart, &rqEnd);
        --rqStart;
        --rqEnd;    
        
        rqs.emplace_back(rqStart,rqEnd,q);
    }
    printf("------------------------\n");
    /*sort(rqs.begin(),rqs.end(),[](const Pair &p0,const Pair &p1)
    	{
    		//return p0.end < p1.end;
    		return p0.start < p1.start;
    	});*/
    	
    qsort(rqs.data(),nRequests,sizeof(Pair),comparePairs);
    	
    int lastClear = 0;
    
    for(auto &rq : rqs)
    {
    	for(int i=lastClear;i<rq.start;i++)
    	{    		
    		if(buf[i]!=INF) 
    		{
    			//update(i,INF);
    			//t[i] = INF;
    			update(1,0,sz-1,i,INF);
    			debug("update %d",i);
    			//printT();
    		}
    	}
    	lastClear = rq.start;
    	
    	//rq.minDist = getmin(rq.end);
    	rq.minDist = sumT(1,0,sz-1,rq.start,rq.end);
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