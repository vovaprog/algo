#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int n,k;
    
    scanf("%d%d",&n,&k);
    
    vector<int> input;
    queue<int> q;
    int maxSize = 0, maxEnd = -1;
    int counter = 0;

    for(int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d",&a);
        input.push_back(a);

        if(a==0)
        {
        	++counter;
        	while(counter>k && q.size()>0)
        	{        		
        		int t = q.front();
        		if(t==0) --counter;
        		q.pop();
        	}
        }
        if(counter<=k || a==1)
        {
    		q.push(a);
    	}
    	if(q.size()>maxSize)
    	{
    		maxSize = q.size();
    		maxEnd = i+1;
    	}
    }
    
    int maxStart = maxEnd - maxSize;

    printf("%d\n",maxSize);

    if(maxSize==0)
    {
    	for(int i : input) printf("%d ",i);
	}
    else
	{
	    for(int i=0;i<maxStart;++i)
	    {
	    	printf("%d ",input[i]);
	    }

	    for(int i=maxStart;i<maxEnd;++i)
	    {
	    	printf("1 ");
	    }

	    for(int i=maxEnd;i<n;++i)
	    {
			printf("%d ",input[i]);
	    }
	}
    
    printf("\n");
    
    return 0;
}

