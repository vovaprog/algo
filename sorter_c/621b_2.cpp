#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline long long int countPairs(long long int x)
{
    if(x<1) return 0;
    x=x-1;
    long long int result = 0;
    while(x>0)
    {
        result+=x;
        x--;
    }
    return result;   
}

int main()
{
    int n;
    
    cin >> n;
    
    vector<int> diag0(1000*2-1);
    vector<int> diag1(1000*2-1);
        
    for(int i=0;i<n;i++)
    {
        int r, c;
        cin >> r >> c;
        r--;c--;
        
        int indexD0 = r+c;        
        diag0[indexD0]++;
        
        int indexD1 = r-c+1000-1;
        diag1[indexD1]++;
    }
    
    long long int result = 0;
    
    for(int i=0;i<1000*2-1;i++)
    {
        result += countPairs(diag0[i]) + countPairs(diag1[i]);        
    }
    
    cout << result;
    
    return 0;    
}

