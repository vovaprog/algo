#include <stdio.h>

void printList(int *list,int listSize);
void printList(int *list,int start, int end);

int pivot(int *list,int start,int end)
{
    int pv=list[start];
    int si=start;
    int ei=end-1;
    
    while(true)
    {
        while(si<ei && list[si]<pv){si++;}
        while(si<ei && list[ei]>=pv){ei--;}
        if(si<ei)
        {
            int temp=list[si];
            list[si]=list[ei];
            list[ei]=temp;
        }
        else
        {
            return si;
        }        
    }    
}


void quickSort(int *list,int start,int end)
{
    if(end-start<2) return;
    
    int p = pivot(list,start,end);
    
    if(p==start) p++;
    
    quickSort(list,start,p);
    
    quickSort(list,p,end);
}


void quickSort(int *list,int listSize)
{
    quickSort(list,0,listSize);
}

