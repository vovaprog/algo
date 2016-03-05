#include <stdio.h>
#include <string.h>

using namespace std;

#define ZERO 1
#define START 2
#define COMMON 3
#define READ_COMMON 4
#define READ_NUMBER 5
#define NUMBER 6

int main()
{
    int n;
    char s[100001], number[100001];
    
    scanf("%d",&n);
    
    int totalZeros = 0;
    bool numberExists = false;
    
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);

        int type = ZERO;
        int oneIndex = 0;
        int zeros = 0;
        int state = START;        
        
        for(int j=0;s[j]!=0;j++)
        {
            if(state==START)
            {
                if(s[j]=='1')
                {
                    type = COMMON;
                    state = READ_COMMON;
                    oneIndex = j;
                }
                else if(s[j]!='0')
                {
                    type = NUMBER;
                    numberExists = true;
                    state = READ_NUMBER;
                }
            }
            else if(state==READ_COMMON)
            {
                if(s[j]=='0')
                {
                    zeros++;
                }
                else
                {
                    numberExists = true;
                    type = NUMBER;                    
                }
            }
        }
        
        if(type==ZERO)
        {
            printf("0");
            return 0;
        }
        else if(type==COMMON)
        {
            totalZeros += zeros;
        }
        else
        {
            strcpy(number, s+oneIndex);
        }
    }    
    
    if(numberExists)
    {
        printf("%s",number);
    }
    else
    {
        printf("1");
    }
    for(int i=0;i<totalZeros;i++) printf("0");
    
    return 0;    
}

