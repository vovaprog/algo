
void bubbleSort(int *list,int size)
{
	for(int i=size-1;i>0;--i)
	{
		for(int j=0;j<i;++j)
		{
			if(list[j]>list[j+1])
			{
				int temp=list[j+1];
				list[j+1]=list[j];
				list[j]=temp;
			}
		}
	}
}

