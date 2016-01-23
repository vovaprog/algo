#include <stdio.h>
#include <iostream>

using namespace std;

int main_615a()
{
    int nLamps, nButs;    
    cin >>nButs;
    cin >>nLamps;
    
    int *lamps = new int[nLamps];
    for(int i=0;i<nLamps;i++) lamps[i]=0;
    
    int nOn;
    
    for(int i=0;i<nButs;i++)
    {
        cin >> nOn;
        
        for(int j=0;j<nOn;j++)
        {
            int lampIndex;
            cin >> lampIndex;
            lamps[lampIndex-1] = 1;          
        }        
    }
    
    for(int i=0;i<nLamps;i++)
    {
        if(lamps[i]==0)
        {
            printf("NO");
            return 0;
        }
    }
    
    printf("YES");    
    
    return 0;    
}
