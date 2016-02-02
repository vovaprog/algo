#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct El{
    int r,c;
    bool visited0 = false, visited1 = false;
};

inline bool onLine0(const El &e0, const El &e1)
{
    return e1.r - e0.r == e1.c - e0.c;
}

inline bool onLine1(const El &e0, const El &e1)
{
    return e1.r - e0.r == e0.c - e1.c;
}

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
    
    vector<El> els(n);
        
    for(int i=0;i<n;i++)
    {
        cin >> els[i].r >> els[i].c;
    }
    
    sort(els.begin(), els.end(), [](const El &e0, const El &e1)
        {
            return e0.r < e1.r;    
        });
    
    long long int result = 0;    
    
    for(int i=0;i<n;i++)
    {
        if(!els[i].visited0 || !els[i].visited1)
        {        
            long long int counter0=1, counter1 = 1;
            
            for(int j=i+1;j<n;j++)
            {
                if(!els[i].visited0 && onLine0(els[i],els[j]))
                {
                    counter0++;
                    els[j].visited0=true;
                }
                if(!els[i].visited1 && onLine1(els[i],els[j]))
                {
                    counter1++;
                    els[j].visited1=true;
                }                
            }       
            result += countPairs(counter0) + countPairs(counter1); 
        }
    }
    
    cout << result;
    
    return 0;    
}

