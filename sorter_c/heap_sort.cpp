#include <iostream>

using namespace std;

void moveDown(int *list, int listSize, int startIndex)
{
    int parent=startIndex;
    
    int leftChild  = 2*parent + 1;
    int rightChild = 2*parent + 2;   
    int maxNode;
    
    while(leftChild < listSize)
    {
        maxNode=parent;
        
        if(list[parent]<list[leftChild])
        {
            maxNode=leftChild;
        }
        if(rightChild<listSize && list[maxNode]<list[rightChild])
        {
            maxNode=rightChild;
        }
        
        if(maxNode==parent)
        {
            return;    
        }
        else
        {
            int temp=list[parent];
            list[parent]=list[maxNode];
            list[maxNode]=temp;
            
            parent=maxNode;
        }
        
        leftChild  = 2 * parent + 1;
        rightChild = 2 * parent + 2;             
    }    
}

void makeHeap(int *list, int listSize)
{
    int startIndex = (listSize-2)/2;
    
    while(startIndex>=0)
    {
        moveDown(list,listSize,startIndex);
        startIndex--;        
    }    
}

void sort(int *list, int listSize)
{
    for(int j=listSize-1;j>0;j--)
    {
        int temp=list[j];
        list[j]=list[0];
        list[0]=temp;
        
        moveDown(list,j,0);
    }    
}

void heapSort(int *list, int listSize)
{
    makeHeap(list,listSize);
    
    sort(list,listSize);    
}

