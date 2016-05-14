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

set<int> div1, div2;

int calc(int x)
{
    return x + 1;
}

int calc2(int x)
{
    return x - 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    
    int maxDiv1 = 0, minDiv2 = 1000000;
    
    for(int i = 0; i < m; ++i)
    {
        int d1, d2;
        cin >> d1 >> d2;
        if(d2 < d1) swap(d1, d2);
        
        if(div1.count(d2)!=0 || div2.count(d1)!=0 ||
            minDiv2<d1 || maxDiv1>d2)
        {
            cout <<"0\n";
            return 0;
        }
        
        div1.insert(d1);
        div2.insert(d2);
        
        if(d1>maxDiv1) maxDiv1 = d1;
        if(d2<minDiv2) minDiv2 = d2; 
    }

    int result = 0;
    
    if(div1.size()>0)
    {
        int div1Max = *div1.rbegin();
        int div2Min = *div2.begin();
        
        int count = div2Min - div1Max;
        
        count -= 1;       
        
        result = calc(count);
    }
    else
    {
        result = calc2(n);
    }
    
    cout << result << "\n";    

    return 0;
}
