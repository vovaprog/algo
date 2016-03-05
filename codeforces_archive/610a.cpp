#include <stdio.h>

using namespace std;

int main()
{
    int n, counter=0;
    scanf("%d",&n);
    

    for(int i=2;i<n/2;i+=2)
    {
        int smallSides = i;
        int bigSides = n - i;
        
        if((smallSides & 1)==0 && (bigSides & 1)==0)
        {
            counter++;   
        }        
    }
    
    printf("%d",counter);
    
    return 0;    
}

