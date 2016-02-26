#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

int main()
{
    int a,b,c;
    
    scanf("%d %d %d",&a,&b,&c);
    
    int divA = c / a;
    int divB = c / b;
    
    for(int qa = 0; qa < divA+2; ++qa)
    {
        for(int qb = divB + 2; qb>=0; --qb)
        {            
            if(a * qa + b * qb == c)
            {
                printf("Yes");
                return 0;
            }            
        }
    }
    
    printf("No");
    
    return 0;
}
