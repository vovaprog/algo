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

struct Point{
    int d;
    int count = 1;

};

struct Par{
    int v1, v2;    
};

set<Point> s;
vector<Point> v;
map<Par, set<Par>> m;


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        Point p;
        cin >> p.d;
        
        if(s.count(p)!=0)
        {
            auto it = s.find(p);
            ++it->count;
        }
        else
        {
            s.insert(p);    
        }
    }

    v.reserve(n);
    
    for(auto it : s)
    {
        v.push_back(*it);    
    }
    
    for(int i=0;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            Par p;
            p.d1 = v[i].d;
            p.d2 = v[j].d;

            Par idx;
            idx.v1 = i;
            idx.v2 = j;
            
            m[p].insert(idx);            
        }
    }
    
    int result = 0;
    
    for(auto it : m)
    {
        auto &st = it->second;
        if(st.size()>1)
        {
            for(auto stIt : st)
            {
                Pair &p = *stIt;
                
                int count = min(v[p.v1].count,v[p.v2].count);
            }
        }        
    }
    
    return 0;
}
