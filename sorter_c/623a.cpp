#include <stdio.h>
#include <set>
#include <string.h>
#include <stdarg.h>
#include <algorithm>

using namespace std;

set<int> vs[500];
char result[501] = {0};

int main()
{    
    int vCount, eCount;
    
    scanf("%d %d", &vCount, &eCount);
    
    for(int i=0;i<eCount;i++)
    {
        int v0, v1;
        scanf("%d %d", &v0, &v1);
        
        --v0;
        --v1;
        vs[v0].insert(v1);
        vs[v1].insert(v0);
    }
    
    int i;
    for(i=0;i<vCount && vs[i].size() == vCount-1;i++)
    {
        result[i] = 'b';        
    }
    
    int aLinks = 0, cLinks = 0;
    
    if(i<vCount)
    {
        result[i] = 'a';
        
        for(auto &link : vs[i])
        {
            if(result[link]==0)
            {
                if(vs[link].size()==vCount-1)
                {
                    result[link] = 'b';    
                }
                else
                {
                    result[link] = 'a';
                    aLinks++;
                }
            }
        }
        
        for(;i<vCount && result[i]!=0;i++);
        
        if(i<vCount)
        {
            result[i] = 'c';
            
            for(auto &link : vs[i])
            {
                if(vs[link].size()<vCount-1)
                {
                    if(result[link]==0)
                    {                        
                        result[link] = 'c';
                        cLinks++;
                    }
                    else
                    {
                        printf("No\n");
                        return 0;
                    }
                }
            }            
        }
    }

    if(strlen(result)<vCount)
    {
        printf("No\n");      
        return 0;
    }
    
    for(int i=0;i<vCount;i++)
    {
        int counter=0;
        if(result[i]=='a')
        {
            for_each(vs[i].begin(),vs[i].end(), 
                [vCount, &counter](int link)
                {
                    if(vs[link].size()<vCount - 1)
                    {
                        counter++;
                    }
                 });                        
                        
            if(counter!=aLinks)
            {
                printf("No\n");
                return 0;
            }            
        }
        else if(result[i]=='c')
        {
            for_each(vs[i].begin(),vs[i].end(), 
                [vCount, &counter](int link)
                {
                    if(vs[link].size()<vCount - 1)
                    {
                        counter++;
                    }
                 });                        
                                   
            if(counter!=cLinks)
            {
                printf("No\n");
                return 0;
            }            
        }

    }
    
    printf("Yes\n%s",result);        
        
    return 0;
}

