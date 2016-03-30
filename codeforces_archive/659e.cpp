#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

set<int> towns[100010];
int ts[100010]={0};

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
    
    for(int i=0;i<nTowns;i++)
    {
        ts[i] = i;
    }
    
    sort(ts, ts+nTowns, 
        [](const int t0,const int t1)
        {
            return towns[t0].size()<towns[t1].size();    
        });

    int result = 0;
    
    for(int q=0;q<nTowns;q++)
    {
        int i = ts[q];

        set<int>& rs = towns[i];
        
        if(rs.size()==0)
        {
            ++result;
        }
        else
        {
            int maxSize=0,maxInd=-1;

            for(int v : rs)
            {
                if(towns[v].size()>maxSize)
                {
                    maxSize = towns[v].size();
                    maxInd = v;
                }
            }
                        
            rs.erase(maxInd);
            towns[maxInd].erase(i);
        }
    }
    
    printf("%d\n",result);
    
    return 0;
}

