#include <bits/stdc++.h>

using namespace std;

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int64 n, qLimit;
    
    cin >>n>>qLimit;
    
    queue<int64> output;
    int64 negCount = 0;
    int64 lastTime = 0;
    
    for(int64 i = 0; i < n; ++i)
    {
        int64 t, d;
        cin >>t>>d;
        
        while(output.size()>0)
        {
        	int64 out = output.front();
        	
        	if(out<=t)
        	{
        		cout <<out<<" ";
        		
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
		int64 out = output.front();
		cout <<out <<" ";
		output.pop();		
	}
    
    return 0;
}
