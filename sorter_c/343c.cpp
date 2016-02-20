#include <bits/stdc++.h>

using namespace std;

void debug(const char *format, ...)
{
    /*va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}

int sum(int *a, int n)
{
    int result = 0;
    for(int i=0;i<n;i++)
    {
        result += a[i];
    }
    return result;
}

int countBr(int n, int cur, int minValue, int maxValue)
{
    int a[10000];
    
    for(int i=0;i<n;i++) a[i] = 1;
    
    for(int q=0;q<n-1;q++)
    {
        a[q] = 1;
        for(int i=q;i<n;i++)
        {
            a[i] = 1;
            for(int j=i+1;j<n;j++)
            {
                a[j]=1;
            }
            
        }        
    }
    
    for(int i=0;i<n-1;i++)
    {
        a[i] = 1;
        for(int j=i+1;j<n;j++)
        {
            
        }        
    }
    
    countBr(n-1,-1,minValue,maxValue);
    countBr(n-1,1,minValue,maxValue);
}

int main()
{
    int nTotal, nMiddle;
    char middle[100010];
    
    scanf("%d %d",&nTotal,&nMiddle);
    scanf("%s",middle);
    
    int midCount = 0;
    
    for(int i=0;i<nMiddle;i++)
    {
        if(middle[i]=='(') midCount++;
        else midValue--;
    }
    
    int n = nTotal - nMiddle;
    
    for(int i=0;i<=n;i++)
    {
        if(midCount<0)
        {
            minValue = midCount;
            maxValue = midCount+(n-i);
            
            
        }
        else
        {
            minValue = 0;
            maxValue = midCount+n-i;
        }
        
        result += countBr(i, minValue, maxValue);
        
        if(midCount>0)
        {
            minValue = midCount;
            maxValue = i + midCount;
        }
        else
        {
            minValue = i - midCount;
            maxValue = i + midCount;
        }
        
        if(minValue>=0 && maxValue>=0)
        {
            countBr2(n-i,minValue,maxValue);
        }
    }
    
    
    
    
    return 0;
}


