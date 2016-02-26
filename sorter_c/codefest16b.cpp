#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int64 zeros;
    
    cin >> zeros;
    
    scanf("%d",&zeros);
    
    vector<int64> powers;
    int64 v = 1, base = 5;
    
    for(int64 i=1;i<9;i++)
    {
    	powers.push_back(v*=base);    
    }
    
    int64 counter = 0;
    
    for(int64 i=1;;i++)
    {      
    	for(auto v : powers)
    	{
    		if(i % v==0)
    		{
    			counter++;	
    		}
    	}

    	if(counter==zeros)
    	{
    		cout <<"5"<<endl;

    		for(int j=i;j<i+5;j++)
    		{
    			cout <<j<<" ";
    		}
    		return 0;
    	}
    	else if(counter>zeros)
    	{
    		cout <<"0";
    		return 0;
    	}
    }
    
    return 0;
}
