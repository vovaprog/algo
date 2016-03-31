#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

set<int> towns[100010];
bool visited[100010]={false};

int walkTree(int cur, int parent)
{
	visited[cur] = true;
	set<int> &rs = towns[cur];
	
	for(int r : rs)
	{
		if(r==parent) continue;
		
		if(visited[r]) return 0;
		
		if(walkTree(r,cur)==0) return 0;
	}
	
	return 1;
}

int main()
{
    int nTowns,nRoads;
    
    scanf("%d %d",&nTowns,&nRoads);
    
    for(int i = 0; i < nRoads; ++i)
    {
        int v0,v1;
        scanf("%d %d",&v0,&v1);
        --v0;--v1;
        towns[v0].insert(v1);
        towns[v1].insert(v0);        
    }

    int result = 0;
    
    for(int i=0;i<nTowns;++i)
    {
    	if(!visited[i])
    	{
    		result += walkTree(i,-1);
    	}    	
    }
    
    printf("%d\n",result);
    
    return 0;
}

