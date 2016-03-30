#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int nToys, money;
    
    scanf("%d %d",&nToys, &money);

    set<int> toys;
    
    for(int i = 0; i < nToys; ++i)
    {
        int toy;
        scanf("%d",&toy);        
        toys.insert(toy);
    }
    
    int prev = 0;    
    int result = 0;

    vector<int> output;
    
    for(int toy : toys)
    {
        for(int i = prev+1;i<toy && money>=i;i++)
        {
            ++result;
            money -= i;
            output.push_back(i);
        }
        if(money<=0) 
        {
            break;
        }
        prev = toy;
    }
    
    for(int i = prev+1;money>=i;i++)
    {
        ++result;
        money-=i;          
        output.push_back(i);
    }
    
    printf("%d\n",result);

    for(int out : output)
    {
        printf("%d ",out);
    }
    
    printf("\n");
    
    return 0;
}
