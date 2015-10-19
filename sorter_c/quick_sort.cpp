#include <stdio.h>

void printList(int *list,int listSize);

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
            //si++;
            //ei--;
        }
        else
        {
            return si;
        }        
    }    
}


void quickSort(int *list,int start,int end)
{
    printf("<<%d : %d>>",start,end);
    
    if(end-start<1) return;
    
    int p = pivot(list,start,end);
    /*printf(" res pivot = %d\n",p);
    printf("res:");
    printList(list+start,end-start);*/    
    
    //if(p<end)
    {
        quickSort(list,start,p);
    }
    
    //if(p>start)
    {
        quickSort(list,p,end);
    }
}


void quickSort(int *list,int listSize)
{
    quickSort(list,0,listSize);
}

