#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdarg.h>
#include <algorithm>

using namespace std;

vector<int> vs[500];
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
        vs[v0].push_back(v1);
        vs[v1].push_back(v0);
    }
    
    int i;
    for(i=0;i<vCount && vs[i].size() == vCount-1;i++)
    {
        result[i] = 'b';        
    }
    
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

    int aLinks = -1, cLinks = -1;
    
    for(int i=0;i<vCount;i++)
    {
        int counter=0;
        if(result[i]=='a')
        {
            if(aLinks == -1)
            {
                aLinks = vs[i].size();
            }
            else if(vs[i].size()!=aLinks)
            {
                printf("No\n");
                return 0;
            }
        }
        else if(result[i]=='c')
        {
            if(cLinks == -1)
            {
                cLinks = vs[i].size();
            }
            else if(vs[i].size()!=cLinks)
            {
                printf("No\n");
                return 0;
            }
        }
    }
    
    printf("Yes\n%s",result);        
        
    return 0;
}

