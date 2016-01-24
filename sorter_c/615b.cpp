#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

long long int maxBeauty = 0;

struct Line{
    int start,end;
    int maxTail;
};

Line *lines;

int nPoints, nLines;

int pointCounts[100001]={0};
int pointIndexes[100001]={0};
int endPoints[200000];

void findBeauty(int curI, int tailLength)
{
    tailLength += 1;
    
    lines[curI].maxTail = tailLength;
    
    long long int curBeauty = (long long )pointCounts[lines[curI].end] * (long long )(tailLength+1);
    
    if(curBeauty > maxBeauty)
    {
        maxBeauty = curBeauty;    
        
        //printf("MAX Beauty s: %d   e: %d   l: %d   h: %d   beauty: %d\n",lines[curI].start,lines[curI].end,tailLength, numberOfHair, maxBeauty);
    }    
     
    curBeauty = (long long )pointCounts[lines[curI].start] * (long long )(tailLength);
    
    if(curBeauty > maxBeauty)
    {
        maxBeauty = curBeauty;    
    }
    
    if(pointIndexes[lines[curI].end]!=0)
    {
        for(int i=pointIndexes[lines[curI].end];i<nLines && lines[i].start == lines[curI].end;i++)
        {
            if(lines[i].maxTail<=tailLength+1)
            {
                findBeauty(i, tailLength);
            }
        }
    }
}

int compareInt( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     return int_a - int_b;
}

int compareLine( const void* al0, const void* al1)
{
    return ((Line*)al0)->start - ((Line*)al1)->start;    
    
     /*int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     return int_a - int_b;*/
}

//==============================================================
//==============================================================
//==============================================================



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




void merge2(Line *list,int start,int middle,int end, Line *mergeOutput)
{
    int i,j,outCounter=0;
    for(i=start,j=middle;i<middle && j<end;)
    {
        if(list[i].start<=list[j].start)
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

void mergeSort2(Line *list,int start, int end,Line *mergeOutput)
{
    int listSize=end - start;
    
    if(listSize>1)
    {
        mergeSort2(list,start,start+listSize/2,mergeOutput);
        mergeSort2(list,start+listSize/2,end,mergeOutput);
        merge2(list,start,start+listSize/2,end,mergeOutput);
    }    
}

void mergeSort2(Line *list,int listSize)
{
    Line *mergeOutput2=new Line[listSize];
    
    mergeSort2(list,0,listSize,mergeOutput2);
    
    delete[] mergeOutput2;
}



//==============================================================
//==============================================================
//==============================================================






#ifdef REPLACE_MAIN
int main_615b()
#else
int main()
#endif
{
    memset(pointCounts, 0, sizeof(int) * 100001);
    memset(pointIndexes, 0, sizeof(int) * 100001);
    
    scanf("%d %d", &nPoints, &nLines);
    
    lines = new Line[nLines];
    
    for(int i=0;i<nLines;i++)
    {
        scanf("%d %d", &(lines[i].start), &(lines[i].end));
        if(lines[i].start>lines[i].end)
        {
            int temp = lines[i].end;
            lines[i].end = lines[i].start;
            lines[i].start = temp;
        }
        lines[i].maxTail = 0;
        endPoints[i]=lines[i].end;
    }
    
    /*sort(lines, lines + nLines, [] (Line &l0, Line &l1) 
        { return l0.end < l1.end; });

    
    int prevValue = lines[0].end;
    int count = 0;
    
    for(int i=0;i<nLines;i++)
    {   
        if(lines[i].end!=prevValue)
        {
            pointCounts[prevValue] = count;
            
            count = 1;
            prevValue = lines[i].end;
        }
        else
        {
            count++;    
        }
    }
    
    pointCounts[prevValue]=count;*/
    
    //qsort( endPoints, nLines, sizeof(int), compareInt );
    mergeSort(endPoints, nLines);   
    
    int prevValue = endPoints[0];
    int count = 0;
    
    for(int i=0;i<nLines;i++)
    {   
        if(endPoints[i]!=prevValue)
        {
            pointCounts[prevValue] = count;
            
            count = 1;
            prevValue = endPoints[i];
        }
        else
        {
            count++;    
        }
    }
    
    pointCounts[prevValue]=count;
    
    
    
    /*sort(lines, lines + nLines, [] (Line &l0, Line &l1) 
        { return l0.start < l1.start; });*/
        
    //qsort( lines, nLines, sizeof(Line), compareLine );
    mergeSort2(lines, nLines);
    
    
    prevValue = lines[0].start;
    count = 0;
    
    pointIndexes[prevValue] = 0;
    
    for(int i=0;i<nLines;i++)
    {   
        if(lines[i].start!=prevValue)
        {
            pointCounts[prevValue] += count;
            
            count = 1;
            prevValue = lines[i].start;
            
            pointIndexes[prevValue] = i;
        }
        else
        {
            count++;    
        }
    }
    
    pointCounts[prevValue] += count;    
    
    /*for(int i=0;i<nLines;i++)
    {   
        if(lines[i].maxTail == 0)
        {
            findBeauty(i,0);
        }
    } */
    
    for(int curI=0;curI<nLines;curI++)
    {
        long long int curBeauty = (long long )pointCounts[lines[curI].end] * (long long )(lines[curI].maxTail+2);
        
        if(curBeauty > maxBeauty)
        {
            maxBeauty = curBeauty;    
        }    

        curBeauty = (long long )pointCounts[lines[curI].start] * (long long )(lines[curI].maxTail+1);
        
        if(curBeauty > maxBeauty)
        {
            maxBeauty = curBeauty;    
        }
        
        
        if(pointIndexes[lines[curI].end]!=0)
        {
            for(int i=pointIndexes[lines[curI].end];i<nLines && lines[i].start == lines[curI].end;i++)
            {
                if(lines[i].maxTail<lines[curI].maxTail+1)
                {
                    lines[i].maxTail = lines[curI].maxTail+1;
                }
            }
        }
            
    }
    
    //printf("%l64d",maxBeauty);
    cout << maxBeauty;
    
    return 0;    
}

