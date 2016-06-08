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

map<int,int> m;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int sum = 0;
    
    for(int i = 0; i < 5; ++i)
    {
        int r;
        cin >> r;
        m[r] = m[r] + 1;
        sum += r;
    }

    vector<int> v;
    
    for(auto p : m)
    {
        if(p.second>1)
        {
            int count = p.second;
            if(count > 3) count = 3;
            v.push_back(p.first * count);
        }        
    }
    
    int result;
    
    if(v.size()>0)
    {
        sort(v.begin(), v.end());
        result = sum - v[v.size() - 1];
    }
    else
    {
        result = sum;    
    }
    
    cout << result << endl;    
    
    return 0;
}
