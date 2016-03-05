#include <iostream>
#include <climits>

using namespace std;


int main()
{
    unsigned long long l, r, k, p;
    int exists = 0;
        
    cin >> l;
    cin >> r;
    cin >> k;
    
    p = 1;
    
    unsigned long long limit = 0;
    
    if(k!=0)
    {
        limit = ULLONG_MAX / k;
    }
    
    while(p<=r)
    {
        if(p>=l && p<=r)
        {
            exists=1;
            cout << p << " ";
        }        
        if(p > limit) 
        {
            break;
        }
        p *= k;        
    }
    
    if(!exists)
    {
        cout <<"-1";
    }
    
    return 0;    
}

