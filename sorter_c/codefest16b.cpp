#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef unsigned long long int int64;

int64 fact(int64 x)
{
    int64 result=x;
    for(int64 i=x-1;i>=2;i--)
    {
        result*=i;
    }
    return result;
}

int main()
{
    int zeros;
    
    scanf("%d",&zeros);
    
    int start = zeros * 5;
    
    /*for(int i=start;i<start+5;i++)
    {
        printf("%d",i
    }*/
    
    
    for(int64 i=1;i<30;i++)
    {
        cout <<"fact("<<i<<")="<<fact(i)<<endl;        
    }
    
    
    
    
    return 0;
}
