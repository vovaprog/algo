#include <stdio.h>
#include <string.h>

using namespace std;

int maxBeauty = 0;

struct Line{
    int start,end;
};

Line *lines;

//set<int> visited;
int visited[200000];

int nPoints, nLines;

inline int calcTail(int checkI)
{
    int count=0;
    for(int i=0;i<nLines;i++)
    {        
        if(lines[i].start==checkI || lines[i].end==checkI)
        {
            count++;
        }
    }    
    return count;
}

void findBeauty(int curI, int tailLength)
{
    //printf("findBeauty %d %d\n",curI,tailLength);

    tailLength+=1;
    
    int numberOfHair = calcTail(lines[curI].end);
    
    if(numberOfHair * (tailLength+1) > maxBeauty)
    {
        maxBeauty = numberOfHair * (tailLength+1);    
        
        //printf("MAX Beauty s: %d   e: %d   l: %d   h: %d   beauty: %d\n",lines[curI].start,lines[curI].end,tailLength, numberOfHair, maxBeauty);
    }    
    
    visited[curI] = 1;
    
    for(int i=0;i<nLines;i++)
    {
        if(lines[i].start==lines[curI].end &&           
            visited[i]==0)
        {
            findBeauty(i, tailLength);
        }
    }
    
    visited[curI] = 0;
}

#ifdef REPLACE_MAIN
int main_615b()
#else
int main()
#endif
{
    memset(visited, 0, sizeof(int) * 200000);
    
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
    }
    
    for(int i=0;i<nLines;i++)
    {        
        findBeauty(i,0);        
    }    
    
    printf("%d",maxBeauty);
    
    return 0;    
}

