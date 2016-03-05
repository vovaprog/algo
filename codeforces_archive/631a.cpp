#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

int main()
{
	int n;
	
    scanf("%d",&n);
    
    int a, b;
    int sumA=0, sumB=0;
    
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&a);
    	sumA = (sumA | a);
    }
    
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&b);
    	sumB = (sumB | b);    	
    }
    
    int result = sumA + sumB;
    
    printf("%d",result);
    
    return 0;
}