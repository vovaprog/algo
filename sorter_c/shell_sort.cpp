
void shellSort(int *list, int listSize)
{
	for(int step=listSize/2;step>=1;step/=2)
	{
		for(int i=step;i<listSize;i+=step)
		{
		    int x = list[i];
	    
			int j=i;
		    for(;j>0 && list[j-step] > x ;j-=step)
		    {
		        list[j]=list[j-step];
		    }
	    
		    list[j]=x;
		}
	}
}

