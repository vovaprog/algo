#include <bits/stdc++.h>

using namespace std;

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

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

bool compareBlocksS(int ind0, int ind1)
{
    if(ind1==0 || ind1==sbs.size()-1) swap(ind0,ind1);
    
    if(ind0 == 0 || ind0==sbs.size()-1)
    {
        if(sbs[ind0].c == sbs[ind1].c &&
            sbs[ind0].count<=sbs[ind1].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(sbs[ind0].c == sbs[ind1].c &&
            sbs[ind0].count==sbs[ind1].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    
}

bool compareBlocksT(int indT, int indS)
{
    if(indS == 0 || indS==sbs.size()-1)
    {
        if(tbs[indT].c == sbs[indS].c &&
            tbs[indT].count>=sbs[indS].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(tbs[indT].c == sbs[indS].c &&
            tbs[indT].count==sbs[indS].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    
}


int* prefix_function() 
{
	int n = (int) sbs.size();
	int *pi = new int[n];
	pi[0] = 0;
	for (int i=1; i<n; ++i) 
	{
		int j = pi[i-1];
		while (j > 0 && !compareBlocksS(i,j))
		{
			j = pi[j-1];
		}
		if (compareBlocksS(i,j))  
		{
		    ++j;
		}
		pi[i] = j;
	}
	return pi;
}


int64 knutSearch()
{
    int64 counter=0;

    int *d = prefix_function();
    int k = 0;
            
    int i,j;
    for(i=0,j=0;i<tbs.size() && j<sbs.size();++i)
    {
        while(j>0 && !compareBlocksT(i,j))
        {
			j=d[j-1];
		}
		if(compareBlocksT(i,j)) 
		{
		    j++;
		}
		if (j==sbs.size())
        {
            counter++;  
            j=d[j-1];
        }               
    }
    return counter;
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
    		sbs[sbs.size()-1].count += b.count;    		
    	}
    	else
    	{
    		sbs.push_back(b);
    	}
    	
    	prevB = b;
    }
    
    int64 counter = 0;
    
    if(sbs.size()<2)
    {
        for(int i=0;i<tbs.size();i++)
        {
            counter += compareOne(i);	    	
        }        
    }
    else
    {
        counter = knutSearch();        
    }
        
    cout <<counter;
    
    return 0;
}
