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

int pointCounts[100001];


void findBeauty(int curI, int tailLength)
{
    tailLength += 1;
    
    lines[curI].maxTail = tailLength;
        
    int numberOfHair = pointCounts[lines[curI].end];
    
    if(numberOfHair * (tailLength+1) > maxBeauty)
    {
        maxBeauty = numberOfHair * (tailLength+1);    
        
        //printf("MAX Beauty s: %d   e: %d   l: %d   h: %d   beauty: %d\n",lines[curI].start,lines[curI].end,tailLength, numberOfHair, maxBeauty);
    }    
    
    for(int i=curI+1;i<nLines && lines[i].start <= lines[curI].end;i++)
    {
        if(lines[i].start==lines[curI].end && lines[i].maxTail<=tailLength+1)
        {
            findBeauty(i, tailLength);
        }
    }
}

#ifdef REPLACE_MAIN
int main_615b()
#else
int main()
#endif
{
    memset(pointCounts, 0, sizeof(int) * 100000);
    
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
    }
    
    sort(lines, lines + nLines, [] (Line &l0, Line &l1) 
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
    
    pointCounts[prevValue]=count;
    
    
    
    sort(lines, lines + nLines, [] (Line &l0, Line &l1) 
        { return l0.start < l1.start; });
    
    
    
    prevValue = lines[0].start;
    count = 0;
    
    for(int i=0;i<nLines;i++)
    {   
        if(lines[i].start!=prevValue)
        {
            pointCounts[prevValue] += count;
            
            count = 1;
            prevValue = lines[i].start;
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

