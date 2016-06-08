#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

//=====================================================================
#define debug3(args...) { vector<string> v = splitArgNames(#args); debugPrint(v.begin(), args); }
vector<string> splitArgNames(const string& s) 
{ vector<string> v; stringstream ss(s); for (string x; getline(ss, x, ',');) { v.emplace_back(x); } return move(v); }
void debugPrint(vector<string>::iterator it) { cout <<"\n"; }
template<typename T, typename... Args>
void debugPrint(vector<string>::iterator it, T head, Args... args) 
{ cout << *it <<" = "<< head << "     "; debugPrint(++it, args...); }
//=====================================================================

typedef long long int int64;

int towns[110];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a;

    cin >> n >> a;

    --a;
    
    for(int i = 0; i < n; ++i)
    {
        int r;
        cin >> r;
        towns[i] = r;
    }

    int result = 0;
    
    if(towns[a]!=0)
    {
        ++result;    
    }
    
    int b = a - 1;
    int e = a + 1;
    
    while(b>=0 || e<n)
    {
        if(b>=0 && e<n)
        {
            if(towns[b]!=0 && towns[e]!=0)
            {
                result+=2;        
            }
            --b;
            ++e;
        }
        else if(b>=0)
        {
            if(towns[b]!=0)
            {
                result+=1;    
            }
            --b;
        }
        else if(e<n)
        {
            if(towns[e]!=0)
            {
                result+=1;    
            }
            ++e;
        }        
    }
    
    cout <<result<<endl;
    
    return 0;
}
