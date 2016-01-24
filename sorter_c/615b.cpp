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


int compareInt( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     return int_a - int_b;
}

int compareLine( const void* al0, const void* al1)
{
    return ((Line*)al0)->start - ((Line*)al1)->start;    
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

    
    qsort( lines, nLines, sizeof(Line), compareLine );
    
    
    
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
        
    cout << maxBeauty;
    
    return 0;    
}

