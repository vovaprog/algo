#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

int b[100000];
set<int> gt[100000];
set<int> lt[100000];

int main()
{
    int n;
    
    scanf("%d",&n);
    
    
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(b[i]>b[j])
            {                
                gt[i].insert(j);
                lt[j].insert(i);
            }
        }
    }
    
    int count=0;
    
    while(true)
    {
        int mx = 0, mxI;
        
        for(int i=0;i<n;i++)
        {
            if(gt[i].size()>mx) 
            {
                mx = gt[i].size();
                mxI = i;
            }
            if(lt[i].size()>mx) 
            {
                mx = lt[i].size();
                mxI = i;
            }
        }
    
        if(mx==0)
        {
            break;
        }
        
        if(gt[mxI].size() > lt[mxI].size())
        {
            for(auto &g : gt[mxI])
            {
                lt[g].erase(mxI);
            }
            gt[mxI].clear();
        }       
        
        ++count;
    }        
    
    printf("%d",count);
    
    return 0;
}
