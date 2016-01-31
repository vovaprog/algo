#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int compareInt( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );
     
     return int_a - int_b;
}

int main()
{
    int n;
    
    cin >> n;
    
    int *a = new int[n];
    long long int sum = 0;
    
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        
        sum += a[i];
    }
    
    long long int med = sum / n;
        
    long long int result = 0;
    
    qsort( a, n, sizeof(int), compareInt);
    
    int s=0, e=n-1;
    
    while(s<e)
    {
        while(a[s]>=med && s<e) s++;
        while(a[e]<=med+1 && s<e) e--;
        
        if(s>=e) break;
        
        if(a[s]<med && a[e]>med+1)
        {        
            int stepsNeeded = med - a[s];
            
            int stepsAvail = a[e] - (med + 1);
            if(stepsAvail>stepsNeeded)
            {
                a[s]=med;
                s++;
                a[e]-=stepsNeeded;
                result += stepsNeeded;
            }
            else
            {
                a[s]+=stepsAvail;
                a[e]-=stepsAvail;
                e--;
                result+=stepsAvail;
            }
        }
    }


    s=0; e=n-1;
    
    while(s<e)
    {
        while(a[s]>=med && s<e) s++;
        while(a[e]<=med && s<e) e--;
        
        if(s>=e) break;
        
        if(a[s]<med && a[e]>med)
        {        
            int stepsNeeded = med - a[s];
            
            int stepsAvail = a[e] - med;
            if(stepsAvail>stepsNeeded)
            {
                a[s]=med;
                s++;
                a[e]-=stepsNeeded;
                result += stepsNeeded;
            }
            else
            {
                a[s]+=stepsAvail;
                a[e]-=stepsAvail;
                e--;
                result+=stepsAvail;
            }
        }
    }
    
    s=0; e=n-1;
    
    while(s<e)
    {
        while(a[s]>=med+1 && s<e) s++;
        while(a[e]<=med+1 && s<e) e--;
        
        if(s>=e) break;
        
        if(a[s]<=med && a[e]>=med+1)
        {
            a[s]++;
            a[e]--;
            result++;
        }
    }
        
    cout << result;
    
    return 0;    
}

