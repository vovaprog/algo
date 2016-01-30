#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n, v, min, 
        firstMinIndex, curMinIndex, prevMinIndex, indexDif, maxIndexDif = 0;    
    
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        cin >> v;
        
        if(i==0 || v < min)
        {
            min = v;
            firstMinIndex = prevMinIndex = i;
        }
        else if(v==min)
        {
            indexDif = i - prevMinIndex;
            if(indexDif > maxIndexDif)
            {
                maxIndexDif = indexDif;    
            }
            prevMinIndex = i;
        }
    }
    
    long long int count = 0;
    
    if(prevMinIndex==firstMinIndex)
    {
        count = (long long int)min * n + n - 1;
    }
    else
    {
        int endDif = firstMinIndex + (n - prevMinIndex);
        if(endDif > maxIndexDif) 
        {
            maxIndexDif = endDif;
        }
        
        count = (long long int)min * n +  maxIndexDif - 1;
    }
            
    cout << count;
    
    return 0;    
}

