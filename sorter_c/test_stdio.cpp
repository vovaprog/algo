#include <bits/stdc++.h>

#include "SimpleProfiler.h"

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main2()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
        
    int n;
    
    scanf("%d",&n);
    
    /*{
        SimpleProfiler s("cin");
                
        for(int i = 0; i < n; ++i)
        {
            int r;
            cin >> r;        
        }
    } */   
    
/*    {
        SimpleProfiler s("scanf");
        
        for(int i = 0; i < n; ++i)
        {
            int r;
            scanf("%d",&r);        
        }
    }*/

    {
        SimpleProfiler sp("scanf");
        
        char s[500];
        
        for(int i = 0; i < n; ++i)
        {            
            scanf("%s",s);        
        }
    }
    
    {
        SimpleProfiler sp("cin");
            
        string s;
        
        for(int i = 0; i < n; ++i)
        {            
            cin >> s;
            cout <<"["<<s<<"]   ";
        }
    }     

    return 0;
}
