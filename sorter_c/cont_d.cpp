#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Block{
	int64 count;
	char c;
};

vector<Block> tbs, sbs;

int64 compareOne(int64 tInd)
{
	if(tbs[tInd].c==sbs[0].c && tbs[tInd].count>=sbs[0].count)
	{
		int64 res = tbs[tInd].count - sbs[0].count + 1;
		if(res>0) return res;
		else return 0;
	}
	else
	{
		return 0;	
	}
}

int64 compare(int64 tInd)
{
	if(sbs.size()<2)
	{
		return compareOne(tInd);	
	}
	else
	{
		int64 t, s;
		
		for(t=tInd, s=0;t<tbs.size() && s<sbs.size();t++,s++)
		{
			if(s==0 || s==sbs.size()-1)
			{
				if(sbs[s].count>tbs[t].count) return 0;	
			}
			else	
			{
				if(sbs[s].count!=tbs[t].count) return 0;
			}			
		}
		
		if(s>=sbs.size())
		{
			return 1;
		}
		else
		{
			return 0;	
		}
	}	
}

int main()
{
    int tSize, sSize;
    
    scanf("%d %d",&tSize, &sSize);
        
    tbs.reserve(tSize);
    sbs.reserve(sSize);
    
    Block prevB;
    
    for(int i=0;i<tSize;i++)
    {
    	int cnt;
    	Block b;
    	scanf("%d-%c",&cnt,&b.c);
    	b.count =  cnt;    	
    	
    	if(i>0 && prevB.c == b.c)
    	{
    		tbs[tbs.size()-1].count += b.count;    		
    	}
    	else
    	{
    		tbs.push_back(b);
    	}
    	
    	prevB = b;
    }
    
    for(int i=0;i<sSize;i++)
    {
    	Block b;
    	scanf("%d-%c",&b.count,&b.c);	
    	
    	if(i>0 && prevB.c == b.c)
    	{
    		sbs[tbs.size()-1].count += b.count;    		
    	}
    	else
    	{
    		sbs.push_back(b);
    	}
    	
    	prevB = b;
    }
    
    int64 counter = 0;
    
    for(int i=0;i<tbs.size();i++)
    {
    	counter += compare(i);	    	
    }
    
    cout <<counter;
    
    return 0;
}
