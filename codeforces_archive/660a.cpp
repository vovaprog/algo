#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int gcd (int a, int b) 
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd (b, a % b);
	}
}

int main()
{
    int n;
    
    scanf("%d",&n);
    
    vector<int> output;
    
    for(int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d",&a);
        
        if(i==0)
        {
            output.push_back(a);
        }
        else
        {
            int g = gcd(output[output.size()-1],a);
            if(g!=1)
            {
                output.push_back(1);
            }                
            output.push_back(a);
        }
    }

    printf("%d\n",(int)output.size()-n);
    for(int i : output)
    {
        printf("%d ",i);        
    }
    printf("\n");
    
    
    return 0;
}
