#include <cstdlib>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>

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


void printList(int *list,int start, int end)
{
    cout <<"[";
	for(int i=start;i<end;i++)
	{
		cout <<list[i]<<" ";		
	}
    cout <<"]"<<endl;
}

void printList(int *list,int size)
{
    printList(list,0,size);    
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

class Town{
public:
    int id;
    int weight;
};

bool operator<(const Town &t0, const Town &t1)
{
    return t0.weight < t1.weight; 
}

int compareIntAsc( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     if(int_a<int_b) return -1;
     else if(int_a>int_b) return 1;
     else return 0;
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
            mergeSortSimple(list,listSize);
        }        
        test_sort(list,listSize);
    }
    
    /*{
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
    }*/

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
        {
            SimpleProfiler sp("heap stl");
            heapSortStl(list,listSize);
        }
        test_sort(list,listSize);
    }
    
    
    /*{
        memcpy(list,listOriginal,listSize*sizeof(int));
        int maxBit = mostSignificantBit(maxValue);
        cout <<"max bit: "<<maxBit<<endl;
        
        {
            SimpleProfiler sp("radix");
            radixSortMsd(list,listSize,6);            
        }
        test_sort(list,listSize);
    }*/

    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("quick");
            quickSort(list,listSize);
        }
        test_sort(list,listSize);
    }

    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("merge template");            
            mergeSort(list,listSize);
        }
        test_sort(list,listSize);
    }

    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("std qsort");            
            qsort(list, listSize, sizeof(int), compareIntAsc );
        }
        test_sort(list,listSize);
    }

    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("std sort int");            
            std::sort(list,list+listSize,
                [](const int &t0, const int &t1)
                {
                    return t0<t1;
                });

        }
        test_sort(list,listSize);
    }
    
    {
        Town *towns = new Town[listSize];
        
        for(int i=0;i<listSize;i++)
        {
            towns[i].id = listOriginal[i];
            towns[i].weight = listOriginal[i];
        }
        
        {
            SimpleProfiler sp("merge template towns");            
            mergeSort(towns,listSize);
        }
        
        delete[] towns;
    }

    {
        Town *towns = new Town[listSize];
        
        for(int i=0;i<listSize;i++)
        {
            towns[i].id = listOriginal[i];
            towns[i].weight = listOriginal[i];
        }
        
        {
            SimpleProfiler sp("merge template towns new lambda");            
            mergeSort(towns,listSize,
                [](const Town &t0, const Town &t1)
                {
                    return t0.weight<t1.weight;
                });
        }
        
        delete[] towns;
    }
    
    {
        Town *towns = new Town[listSize];
        
        for(int i=0;i<listSize;i++)
        {
            towns[i].id = listOriginal[i];
            towns[i].weight = listOriginal[i];
        }
        
        {
            SimpleProfiler sp("std sort towns");            
            std::sort(towns,towns+listSize,
                [](const Town &t0, const Town &t1)
                {
                    return t0.weight<t1.weight;
                });
        }
        
        delete[] towns;
    }    
    
    {
        vector<Town> towns(listSize);
        
        for(int i=0;i<listSize;i++)
        {
            towns[i].id = listOriginal[i];
            towns[i].weight = listOriginal[i];
        }
        
        {
            SimpleProfiler sp("sort vector lambda");            
            mergeSort(towns,
                [](const Town &t0, const Town &t1)
                {
                    return t0.weight<t1.weight;
                });
        }        
    }    
    
    {
        memcpy(list,listOriginal,listSize*sizeof(int));
        {
            SimpleProfiler sp("multiset");
            multiset<int> s;
            s.insert(list,list+listSize);
            std::copy(s.begin(), s.end(), list);
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
    //radixSortMsd(list,listSize,6);    
    quickSort(list,listSize);
    
    printList(list,listSize);
    
    test_sort(list,listSize);
}

int main()
{
    try{
        const int listSize=10000000;
        const int maxValue=100000;
        int *list=createList(listSize,maxValue);
        
        speedTest(list,listSize,maxValue);    
        //sortTest(list,listSize);
        //binarySearchTest();
        //reverseListTest();

        //printList(list,listSize);
        //radixSortMsd(list,listSize,6);
        //printList(list,listSize);
        //testSearch();
        //testSearchBoyerMoore();
        //testPrefixFunction();
        //testReverseNeighbors();
        
    	return 0;
    }catch(string s){
        cout <<"exception: "<<s<<endl;
    }
}
