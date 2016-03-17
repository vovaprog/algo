#include <bits/stdc++.h>

using namespace std;

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int n, qLimit;
    
    scanf("%d %d",&n, &qLimit);
    
    queue<int> output;
    int negCount = 0;
    int lastTime = 0;
    
    for(int i = 0; i < n; ++i)
    {
        int t, d;
        scanf("%d %d",&t, &d);
        
        while(output.size()>0)
        {
        	int out = output.front();
        	
        	if(out<=t)
        	{
        		printf("%d ",out);        		
        		
        		if(out<0) --negCount;
        		
        		output.pop();
        	}
        	else 
        	{        		
        		break;        		
        	}
        }
        
        if(output.size()-negCount>qLimit)
        {
        	++negCount;
        	output.push(-1);        	
        }
        else
        {
        	if(output.size()==0)
        	{
        		lastTime = t+d;	
        	}
        	else
        	{
        		lastTime += d;
        	}
        	        	
        	output.push(lastTime);        	
        }
    }
    
	while(output.size()>0)
	{
		int out = output.front();
		printf("%d ",out);
		output.pop();		
	}
    
    return 0;
}
