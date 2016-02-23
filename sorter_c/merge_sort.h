#ifndef _MERGE_SORT_
#define _MERGE_SORT_

#include <functional>
#include <vector>

template<class T, class Less>
void merge(T *list, int start, int middle, int end, T *mergeOutput, Less compareLess)
{
    int i, j, outCounter = 0;
    for(i = start, j = middle; i<middle && j<end; )
    {
        if(compareLess(list[j], list[i]) )
        {
            mergeOutput[outCounter++]=list[j++];
        }                
        else
        {
            mergeOutput[outCounter++]=list[i++];
        }        
    }
    
    while(i < middle)
    {
        mergeOutput[outCounter++]=list[i++];    
    }
    
    while(j < end)
    {
        mergeOutput[outCounter++]=list[j++];
    }
    
    outCounter=0;
    for(int i=start;i<end;i++)
    {
        list[i]=mergeOutput[outCounter++];
    }   
}

template<class T, class Less>
void mergeSort(T *list,int start, int end,T *mergeOutput, Less compareLess)
{
    int listSize = end - start;
    
    if(listSize > 1)
    {
        mergeSort(list, start, start + listSize / 2, mergeOutput, compareLess);
        mergeSort(list, start + listSize / 2, end, mergeOutput, compareLess);
        merge(list, start, start + listSize / 2, end, mergeOutput, compareLess);
    }    
}

template<class T, class Less>
void mergeSort(T *list, int listSize, Less compareLess)
{
    T *mergeOutput = new T[listSize];
    
    mergeSort(list, 0, listSize, mergeOutput, compareLess);
    
    delete[] mergeOutput;
}

template<class T>
void mergeSort(T *list, int listSize)
{
    mergeSort(list, listSize, std::less<T>());    
}

template<class T>
void mergeSort(std::vector<T> &v)
{
    mergeSort(v.data(), v.size(), std::less<T>());    
}

template<class T, class Less>
void mergeSort(std::vector<T> &v, Less compareLess)
{
    mergeSort(v.data(), v.size(), compareLess);    
}

#endif
