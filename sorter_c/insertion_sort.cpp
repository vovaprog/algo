
void insertionSort(int *list,int listSize)
{
	for(int i=1;i<listSize;i++)
	{
	    int x = list[i];
	    
	    int j=i;
	    for(;j>0 && list[j-1] > x ;j--)
	    {
	        list[j]=list[j-1];
	    }
	    
	    list[j]=x;
	}
}


