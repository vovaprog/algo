#include <bits/stdc++.h>

using namespace std;

void debug(const char *format, ...)
{
    /*va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}

int countPairs(int count)
{
    int result = 0;
    
    for(int i=count-1;i>=0;--i)
    {
        result+=i;
    }
    
    return result;
}

int main()
{
    int n;
    char a[105];
    int cols[105];
    int result = 0;        
    
    for(int i=0;i<105;i++) cols[i]=0;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%s",a);
        
        int rowCounter = 0;
        
        for(int j=0;j<n;j++)
        {
            if(a[j]=='C')
            {
                ++rowCounter;
                cols[j]+=1;
            }
        }
        
        if(rowCounter>=2)
        {
            result += countPairs(rowCounter);
        }
    }
    
    for(int j=0;j<n;j++)
    {
        if(cols[j]>=2)
        {
            result += countPairs(cols[j]);    
        }
    }    
    
    printf("%d",result);
    
    return 0;
}


