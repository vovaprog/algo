
static int *mergeOutput;

static void merge(int *list,int start,int middle,int end)
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

static void mergeSort(int *list,int start, int end)
{
    int listSize=end - start;
    
    if(listSize>1)
    {
        mergeSort(list,start,start+listSize/2);
        mergeSort(list,start+listSize/2,end);
        merge(list,start,start+listSize/2,end);
    }    
}

void mergeSortSimple(int *list,int listSize)
{
    mergeOutput=new int[listSize];
    
    mergeSort(list,0,listSize);
    
    delete[] mergeOutput;
}

