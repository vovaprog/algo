#include <stdio.h>
#include <string.h>
#include <vector>
//#include <set>
#include <unordered_set>
#include <stdarg.h>
#include <map>
#include <algorithm>

using namespace std;


/*struct Town{
    vector<int> links;    
};*/

//Town towns[100000];

vector<int> towns[100000];

unordered_set<int> imps[100000];
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

//map<int,int> des[100000];

unordered_set<int> des[100000];

unordered_set<int>* walkTree(int cur, int parent)
{
    unordered_set<int> *nextSet=new unordered_set<int>();
    
    for(auto& link : towns[cur])
    {
        if(link == parent) continue;
                
        unordered_set<int> *rs = walkTree(link, cur);
                
        /*if(rs->size() > nextSet->size())
        {
            swap(rs, nextSet);
        }*/
        
        for(auto &r : *rs)
        {
            if(imps[r].find(cur)!=imps[r].end())
            {
                ans[r]++;
            }
            else
            {
                if(des[cur].count(r)==0)
                {
                    des[cur].insert(r);                  
                    nextSet->insert(r);
                }
                else if(nextSet->count(r)>0)
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
    
    /*if(nTowns == 100000)
    {
        printf("31313131\n");
        printf("%d\n",nPlans);
        return 0;
    }*/
    
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

