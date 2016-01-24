#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int maxBeauty = 0;

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
    
    int curBeauty = pointCounts[lines[curI].end] * (tailLength+1);
    
    if(curBeauty > maxBeauty)
    {
        maxBeauty = curBeauty;    
        
        //printf("MAX Beauty s: %d   e: %d   l: %d   h: %d   beauty: %d\n",lines[curI].start,lines[curI].end,tailLength, numberOfHair, maxBeauty);
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
    
    qsort( endPoints, nLines, sizeof(int), compareInt );    
    
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
    
    
    
    sort(lines, lines + nLines, [] (Line &l0, Line &l1) 
        { return l0.start < l1.start; });
    
    
    
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
    
    for(int i=0;i<nLines;i++)
    {   
        if(lines[i].maxTail == 0)
        {
            findBeauty(i,0);
        }
    }    
    
    printf("%d",maxBeauty);
    
    return 0;    
}

