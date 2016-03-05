#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;


struct Town{
    vector<int> links;    
};

Town towns[100001];
int imps[100001];

#define IMP 1
#define PASS 2
#define ANC 3
#define HAS_IMP 4
#define IMPOS 5

int cuts = 0;

int walkTree(int cur, int parent)
{
    int type;
    
    if(imps[cur])
    {
        type = IMP;    
    }
    else
    {
        type = PASS;    
    }
    
    for(auto& link : towns[cur].links)
    {
        if(link == parent) continue;
        
        int result = walkTree(link, cur);
        
        switch(result){
        case IMP:
            switch(type){
            case IMP:
                cuts = -1;
                return IMPOS;           
            case PASS:
                type = HAS_IMP;
                break;
            case HAS_IMP:
                type = ANC;
                cuts++;
                break;
            }
            break;
        case HAS_IMP:
            switch(type){
            case IMP:
                cuts++;
                break;
            case PASS:                               
                type = HAS_IMP;
                break;
            case HAS_IMP:
                type = ANC;
                cuts++;
                break;
            }
            break;
        case IMPOS:
            return IMPOS;    
        }
    } 
    
    if(type==ANC)
    {
        return PASS;    
    }
    else
    {
        return type;    
    }    
}

int main()
{
    int nTowns, nPlans, imp;
    
    scanf("%d",&nTowns);
    
    for(int i=0;i<nTowns-1;i++)
    {
        int t0, t1;
        scanf("%d %d", &t0, &t1);
        towns[t0].links.push_back(t1);
        towns[t1].links.push_back(t0);        
    }
        
    scanf("%d",&nPlans);
    
    for(int q = 0;q < nPlans;q++)
    {
        int nImp;
        scanf("%d",&nImp);
        memset(imps,0,sizeof(int)*(nTowns+1));
        for(int i=0;i<nImp;i++)
        {            
            scanf("%d",&imp);
            imps[imp]=1;            
        }
        
        cuts = 0;
        walkTree(1, 1);
        printf("%d\n",cuts);
    }
    
    return 0;    
}

