#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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

int *mergeOutput;

void merge(int *list,int start,int middle,int end)
{
    int i,j,outCounter=0;
    for(i=start,j=middle;i<middle && j<end;)
    {
        if(list[i]<=list[j])
        {
            mergeOutput[outCounter++]=list[i];
            ++i;
        }
        else
        {
            mergeOutput[outCounter++]=list[j];
            ++j;
        }        
    }
    
    for(;i<middle;++i)
    {
        mergeOutput[outCounter++]=list[i];    
    }
    for(;j<end;++j)
    {
        mergeOutput[outCounter++]=list[j];
    }
    
    outCounter=0;
    for(int i=start;i<end;i++)
    {
        list[i]=mergeOutput[outCounter++];
    }
}

void mergeSort(int *list,int start, int end)
{
    int listSize=end - start;
    
    if(listSize>1)
    {
        mergeSort(list,start,start+listSize/2);
        mergeSort(list,start+listSize/2,end);
        merge(list,start,start+listSize/2,end);
    }    
}

void mergeSort(int *list,int listSize)
{
    mergeOutput=new int[listSize];
    
    mergeSort(list,0,listSize);
    
    delete[] mergeOutput;
}


int test_sort(int *list,int listSize)
{
    for(int i=0;i<listSize-1;i++)
    {
        if(list[i]>list[i+1])
        {
            return -1;
        }
    }
    
    return 0;
}

int main()
{
    int listSize=10000;
    int *list=new int[listSize];
    
    srand(time(NULL));
    
    for(int i=0;i<listSize;i++)
    {
        list[i]=rand() % 100;
    }

    for(int i=0;i<listSize;i++)
    {
        cout <<list[i]<<" ";
    }    
    cout <<"-----"<<endl;    
    
    //insertionSort(list,listSize);
    //shellSort(list,listSize);
    mergeSort(list,listSize);
    
    for(int i=0;i<listSize;i++)
    {
        cout <<list[i]<<" ";
    }
    
    return 0;
}
