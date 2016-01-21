#include <stdio.h>

using namespace std;

char b0[1000001],b1[1000001];

int main_616a()
{
    scanf("%s",b0);
    scanf("%s",b1);
    
    int i0=0,i1=0;
    
    const char *foundSign = "\0";   
    
    while(b0[i0]=='0'){ i0++; }
    while(b1[i1]=='0'){ i1++; }        
    
    while(b0[i0]==b1[i1] && b0[i0]!=0 && b1[i1]!=0)
    {
        ++i0;
        ++i1;        
    }
    
    if(b0[i0]==0 && b1[i1]==0)
    {
        printf("=");
        return 0;
    }
    
    if(b0[i0]==0 && b1[i1]!=0)
    {
        printf("<");
        return 0;
    }

    if(b0[i0]!=0 && b1[i1]==0)
    {
        printf(">");
        return 0;
    }
    
    if(b0[i0]<b1[i1])
    {
        foundSign = "<";
    }
    else
    {
        foundSign = ">";
    }
    
    while(b0[i0]!=0 && b1[i1]!=0)
    {
        i0++;
        i1++;
    }
    
    if(b0[i0]==0 && b1[i1]==0)
    {
        printf(foundSign);
        return 0;
    }
    
    if(b0[i0]==0 && b1[i1]!=0)
    {
        printf("<");
        return 0;
    }

    if(b0[i0]!=0 && b1[i1]==0)
    {
        printf(">");
        return 0;
    }    
    
    return 0;
}

