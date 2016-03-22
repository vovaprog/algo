#include <algorithm>

using namespace std;

void heapSortStl(int *list, int listSize)
{
    make_heap(list, list+listSize);
    
    for(int i=listSize;i>0;--i)
    {
        pop_heap(list,list+i);
    }       
}

