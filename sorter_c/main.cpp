#include <cstdlib>
#include <iostream>

#include "small_utils.h"
#include "SimpleProfiler.h"
#include "sort_algorithms.h"

using namespace std;


void test_sort(int *list,int listSize)
{
    for(int i=0;i<listSize-1;i++)
    {
        if(list[i]>list[i+1])
        {
            throw string("invalid sort");
        }
    }
}

int* createList(int listSize)
{
    int *list=new int[listSize];
    
	for(int i=0;i<listSize;i++)
	{
		list[i]=rand() % 100;
	}
    
    return list;
}

int* createListCopy(int *list,int listSize)
{
    int *listCopy=new int[listSize];
    
	for(int i=0;i<listSize;i++)
	{
		listCopy[i]=list[i];
	}
    
    return listCopy;
}


void printList(int *list,int listSize)
{
    cout <<"[";
	for(int i=0;i<listSize;i++)
	{
		cout <<list[i]<<" ";		
	}
    cout <<"]"<<endl;
}

void speedTest(int *listOriginal,int listSize)
{
    int *list=new int[listSize];
    
    {
        memcpy(list,listOriginal,listSize*sizeof(int));        
        {
            SimpleProfiler sp("bubble");
            bubbleSort(list,listSize);
        }
        test_sort(list,listSize);
    }

    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("merge");
            mergeSort(list,listSize);
        }        
        test_sort(list,listSize);
    }
    
    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("insertion");
            insertionSort(list,listSize);
        }
        test_sort(list,listSize);
    }
    
    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("shell");
            shellSort(list,listSize);
        }
        test_sort(list,listSize);
    }
    
    delete list;
}

int main()
{
    try{
        const int listSize=30000;
        int *list=createList(listSize);
        
        speedTest(list,listSize);
    
    //printList(list,listSize);
    

//	unsigned int millis=getMilliseconds();

    /*{
        SimpleProfiler sp("bubble");
        bubbleSort(list,listSize);
    }*/

	//millis=getMilliseconds()-millis;

	
	//printList(list,listSize);	

	//cout <<endl<< "millis: "<<millis<<endl;

    	return 0;
    }catch(string s){
        cout <<"exception: "<<s<<endl;
    }
}
