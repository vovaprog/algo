#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

int a[200000];

struct Men{
	int t,r;
};

int compareIntAsc( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     if(int_a<int_b) return -1;
     else if(int_a>int_b) return 1;
     else return 0;
}

int compareIntDesc( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     if(int_a<int_b) return 1;
     else if(int_a>int_b) return -1;
     else return 0;
}

int main()
{
    int n, nMen;
    
    scanf("%d %d",&n,&nMen);
    
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);	
    }
    
    vector<Men> mens;
    mens.reserve(nMen);
    
    int maxR=0, indMaxR=0;
    
    for(int q=0;q<nMen;q++)
    {
    	Men mn;
    	
    	scanf("%d %d",&mn.t,&mn.r);	
    	
    	mens.push_back(mn);
    	
    	if(mn.r>=maxR)
    	{
    		maxR=mn.r;	
    		indMaxR = q;
    	}
    }
    
    vector<int> sortRqs;
    int prevR = -1;
    
    for(int q = nMen-1;q>=0;q--)
    {
    	if(mens[q].r>prevR)
    	{
    		sortRqs.push_back(q);
    		prevR = mens[q].r;
    	}
    	if(q==indMaxR) break;
    }
    
    int lastSort = -1;
    
    for(int sr = sortRqs.size()-1;sr>=0;--sr)
    {
    	int q = sortRqs[sr];
    	
    	if(mens[q].t!=lastSort)
    	{
    		if(mens[q].t==1)
    		{
    			qsort(a, mens[q].r, sizeof(int), compareIntAsc );
    			lastSort = 1;
    		}
    		else
    		{
    			qsort(a, mens[q].r, sizeof(int), compareIntDesc );
    			lastSort = 2;
    		}
    	}
    }
    
    for(int i=0;i<n;i++)
    {
    	printf("%d ",a[i]);	
    }
    
    return 0;
}
