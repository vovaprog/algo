#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <stdarg.h>
#include <map>
#include <algorithm>

using namespace std;


/*struct Town{
    vector<int> links;    
};*/

//Town towns[100000];

vector<int> towns[100000];

set<int> imps[100000];
vector<int> impsByTown[100000];

int ans[100000] = {0};
int impossible[100000] = {0};

int nPlans;

void debug(const char *format, ...)
{
    /*va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}

map<int,int> des[100000];

set<int>* walkTree(int cur, int parent)
{
    set<int> *nextSet=new set<int>();
    
    for(auto& link : towns[cur])
    {
        if(link == parent) continue;
                
        set<int> *rs = walkTree(link, cur);
                
        for(auto &r : *rs)
        {
            if(imps[r].find(cur)!=imps[r].end())
            {
                ans[r]++;
            }
            else
            {
                int desValue = ++des[cur][r];
                if(desValue==1)
                {
                    nextSet->insert(r);
                }
                else if(desValue==2)
                {
                    ans[r]++;
                    nextSet->erase(r);
                }
            }            
        }
        
        delete rs;
    }   
            
    for(auto &r : impsByTown[cur])
    {
        nextSet->insert(r);
    }
    
    return nextSet;
}

int main()
{
    int nTowns, imp;
    
    scanf("%d",&nTowns);
    
    for(int i=0;i<nTowns-1;i++)
    {
        int t0, t1;
        scanf("%d %d", &t0, &t1);
        --t0;--t1;
        towns[t0].push_back(t1);
        towns[t1].push_back(t0);        
    }
        
    scanf("%d",&nPlans);
    
    for(int q = 0;q < nPlans;q++)
    {
        int nImp;
        scanf("%d",&nImp);
        
        for(int i=0;i<nImp;i++)
        {            
            scanf("%d",&imp);
            --imp;
            imps[q].insert(imp);
            impsByTown[imp].push_back(q);
            
            const auto &impsEnd = imps[q].end();
            
            for(auto &t : towns[imp])
            {
                if(imps[q].find(t)!=impsEnd)
                {
                    impossible[q] = 1;                    
                    break;
                }                    
            }
        }        
    }
    
     
    
    walkTree(0, 0);

    for(int i=0;i<nPlans;i++)
    {
        if(impossible[i])
        {
            printf("-1\n");    
        }
        else
        {
            printf("%d\n",ans[i]);
        }
    }
     
    return 0;    
}

