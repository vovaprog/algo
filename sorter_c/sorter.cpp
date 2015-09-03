#include <cstdlib>
#include <iostream>

#include "small_utils.h"

using namespace std;

const int listSize=10000;

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

int main()
{
	int list[listSize];

	for(int i=0;i<listSize;i++)
	{
		list[i]=rand() % 100;
	}

	for(int i=0;i<listSize;i++)
	{
		cout <<list[i]<<" ";		
	}
	cout <<endl<<"--------------"<<endl;

	unsigned int millis=getMilliseconds();

	bubbleSort(list,listSize);

	millis=getMilliseconds()-millis;

	for(int i=0;i<listSize;i++)
	{
		cout <<list[i]<<" ";		
	}	

	cout <<endl<< "millis: "<<millis<<endl;

	return 0;
}
