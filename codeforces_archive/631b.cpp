#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

int a[5000][5000]={0};

set<int> paintedRows;
set<int> paintedCols;

int main()
{
	int nRows,nCols,nRq;
    scanf("%d %d %d",&nRows, &nCols, &nRq);
    
    for(int q=0;q<nRq;q++)
    {
    	int op,ind,clr;
    	scanf("%d %d %d",&op,&ind,&clr);
    	--ind;
    	
    	if(op==1)
    	{
    		if(paintedRows.count(ind)==0)
    		{
				for(int j=0;j<nCols;j++)
				{
					a[ind][j] = clr;	
				}
				paintedRows.insert(ind);
				paintedCols.clear();
			}			
    	}
    	else if(op==2)
    	{
    		if(paintedCols.count(ind)==0)
    		{
				for(int i=0;i<nRows;i++)
				{
					a[i][ind] = clr;	
				}
				paintedCols.insert(ind);
				paintedRows.clear();
			}
    	}    	
    }

    for(int i=0;i<nRows;i++)
    {
    	for(int j=0;j<nCols;j++)
    	{
    		printf("%d ",a[i][j]);	
    	}    	
    	printf("\n");
    }
    
    return 0;
}
