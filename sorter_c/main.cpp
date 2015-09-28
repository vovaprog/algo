#include <cstdlib>
#include <iostream>
#include <string.h>

#include "small_utils.h"
#include "SimpleProfiler.h"
#include "sort_algorithms.h"

using namespace std;

void reverseListTest();

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

int* createList(int listSize, int maxValue)
{
    int *list=new int[listSize];
    
	for(int i=0;i<listSize;i++)
	{
		list[i]=rand() % (maxValue+1);
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

int mostSignificantBit(int x)
{
    int bit=0;
    while(x!=0)
    {
        x = x >> 1;
        bit++;
    }
    return bit;
}

void speedTest(int *listOriginal,int listSize, int maxValue)
{
    int *list=new int[listSize];
    
    /*{
        memcpy(list,listOriginal,listSize*sizeof(int));        
        {
            SimpleProfiler sp("bubble");
            bubbleSort(list,listSize);
        }
        test_sort(list,listSize);
    }*/

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

    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("heap");
            heapSort(list,listSize);
        }
        test_sort(list,listSize);
    }

    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        int maxBit = mostSignificantBit(maxValue);
        cout <<"max bit: "<<maxBit<<endl;
        
        {
            SimpleProfiler sp("radix");
            radixSortMsd(list,listSize,6);            
        }
        test_sort(list,listSize);
    }
        
    
    delete list;
}

void binarySearchTest()
{
    const int listSize=100;
    int *list=new int[listSize];
    
    for(int i=0;i<listSize;i++)
    {
        list[i]=i * 5;
    }
    
    for(int i=0;i<listSize;i++)
    {
        int binarySearchResult = binarySearch2(list,listSize,i);
        
        cout <<"search "<<i<<"   result "<<binarySearchResult<<endl;
        
        /*if(binarySearchResult!=i)
        {
            throw string("invalid binary search!");
        }*/
    }
    
    delete[] list;
}


void sortTest(int *list,int listSize)
{
    printList(list,listSize);
     
    //heapSort(list,listSize);
    radixSortMsd(list,listSize,6);
    test_sort(list,listSize);
    
    printList(list,listSize);
}

int main()
{
    try{
        const int listSize=100000;
        const int maxValue=10;
        int *list=createList(listSize,maxValue);
        
        //speedTest(list,listSize,maxValue);    
        //sortTest(list,listSize);
        //binarySearchTest();
        //reverseListTest();

        //printList(list,listSize);
        //radixSortMsd(list,listSize,6);
        //printList(list,listSize);
        testSearch();
        //testSearchBoyerMoore();
        //testPrefixFunction();
        
    	return 0;
    }catch(string s){
        cout <<"exception: "<<s<<endl;
    }
}
