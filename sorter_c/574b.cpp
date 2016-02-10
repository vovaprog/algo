#include <stdio.h>
#include <set>
#include <string.h>
#include <stdarg.h>
#include <algorithm>

using namespace std;

set<int> *ms[4000];

int main()
{    
    int msCount, pairCount;
    
    scanf("%d %d", &msCount, &pairCount);
    
    for(int i=0;i<msCount;i++)
    {
        ms[i] = new set<int>();    
    }
    
    for(int i=0;i<pairCount;i++)
    {
        int v0, v1;
        scanf("%d %d", &v0, &v1);
        
        --v0;
        --v1;
        ms[v0]->insert(v1);
        ms[v1]->insert(v0);
    }
    
    int minPeople=100500;
    
    for(int i=0;i<msCount-2;i++)
    {
        for(int j=i+1;j<msCount-1;j++)
        {            
            if(ms[j]->count(i)!=0 &&
                ms[i]->size() + ms[j]->size()<minPeople)
            {            
                for(int q=j+1;q<msCount;q++)
                {
                    if(ms[q]->count(i)!=0 && ms[q]->count(j)!=0)
                    {
                        int sz = ms[i]->size() + ms[j]->size() + ms[q]->size(); 
                        if(sz<minPeople)
                        {
                            minPeople = sz;    
                        }
                    }
                }
            }
        }        
    }
        
    if(minPeople == 100500)
    {
        printf("-1");    
    }
    else
    {
        printf("%d\n",minPeople-6);    
    } 
    
    return 0;
}