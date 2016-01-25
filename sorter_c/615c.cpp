#include <stdio.h>
#include <string.h>

using namespace std;

char track[2101];
char s[2101];
int tl,sl;
int indexes[4200];
int sCounter = 0;

int findMaxSubstring(int ti)
{
    int maxLength=0;
    int maxStart=0,maxEnd=0;
    
    for(int startJ=0;startJ<sl;startJ++)
    {
        int matchLength=0;
        for(int j=0;startJ+j<sl;j++)
        {
            if(track[ti+j]==s[startJ+j])
            {
                matchLength++;
            }
            else
            {
                break;
            }
        }
        
        if(matchLength>maxLength)
        {
            maxLength = matchLength;
            maxStart = startJ + 1;
            maxEnd = startJ + matchLength;
        }
    }
    
    if(maxLength<sl)
    {
        for(int startJ=sl-1;startJ>=0;startJ--)
        {
            int matchLength=0;
            for(int j=startJ,q=0;j>=0;j--,q++)
            {
                if(track[ti+q]==s[j])
                {
                    matchLength++;
                }
                else
                {
                    break;
                }
            }
            
            if(matchLength>maxLength)
            {
                maxLength = matchLength;
                maxStart = startJ + 1;
                maxEnd = maxStart - matchLength + 1;
            }
        }    
    }
    
    if(maxLength==0)
    {
        return 0;
    }
    else
    {
        indexes[sCounter*2]=maxStart;
        indexes[sCounter*2+1]=maxEnd;
        
        return maxLength;
    }
}
    
#ifndef REPLACE_MAIN
int main()
#else
int main_615c()
#endif
{
    scanf("%s",s);
    scanf("%s",track);
    
    tl = strlen(track);
    sl = strlen(s);
    
    
    
    for(int i=0;i<tl;)
    {
        int substringLength = findMaxSubstring(i);
        if(substringLength==0)
        {
            printf("-1");
            return 0;
        }
        else
        {
            i+=substringLength;
        }
        sCounter++;
    }
    
    printf("%d\n",sCounter);
    
    for(int i=0;i<sCounter;i++)
    {
        printf("%d %d\n",indexes[i*2],indexes[i*2+1]);
    }
    
    return 0;    
}

