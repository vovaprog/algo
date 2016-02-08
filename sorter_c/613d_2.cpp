#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <stdarg.h>

using namespace std;


struct Town{
    vector<int> links;    
};

Town towns[100000];

set<int> imps[100000];

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

//set<int>*
void walkTree(int cur, int parent, set<int> *nextSet, set<int> *nextDirectImps)
{
    debug("\n\nwalkTree( %d, %d )\n", cur, parent);
    
    //set<int> *nextSet = new set<int>();    
    
    set<int> *rs=new set<int>(), *directImps=new set<int>();
    
    int des[100000] = {0};
    
    for(auto& link : towns[cur].links)
    {
        if(link == parent) continue;
        
        //set<int> *rs = new set<int>();
        
        rs->clear();
        directImps->clear();
        walkTree(link, cur, rs, directImps);
        
        
        debug("\n\nreturn to walkTree( %d, %d )\n", cur, parent);
        
        for(auto &r : *rs)
        {
            if(imps[r].count(cur)>0)
            {
                debug("!!!!! ans inc A %d\n",r);
                ans[r]++;
            }
            else
            {
                debug("des inc %d\n",r);
                des[r]++;
            }            
        }
        
        //delete rs;
        
        for(auto &r : *directImps)
        {
            if(imps[r].count(cur)>0)
            {
                impossible[r] = 1;    
            }
        }
        
        //delete directImps;
    }   
    
    delete rs;delete directImps;
        
    for(int r = 0;r<nPlans;r++)
    {
        debug("iter plan %d   cur %d\n",r, cur);
        /*for(auto &s : imps[r])
        {
            printf("<%d> ",s);    
        }
        printf("\n");*/
        
        
        if(des[r]>1)
        {
            debug("!!!!! ans inc B %d\n",r);
            ans[r]++;    
        }
        else if(des[r]==1 || imps[r].count(cur)>0)            
        {
            debug("next insert %d\n",r);
            nextSet->insert(r);    
        }
        
        if(imps[r].count(cur)>0)
        {
            nextDirectImps->insert(r);    
        }
    }
    
    //return nextSet;
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
        towns[t0].links.push_back(t1);
        towns[t1].links.push_back(t0);        
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
            debug("plan %d   imp %d\n",q, imp);
            imps[q].insert(imp);    
        }        
    }
    
    
    
    set<int> s0,s1;
    
    walkTree(0, 0, &s0, &s1);
    //delete ret;
    
    debug("result: ");
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

