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

int getMin(int v0, int v1, int v2, int v3)
{
    int min0 = min(v0,v1);
    int min1 = min(v2,v3);
    
    return min(min0, min1);
}

int getMax(int v0, int v1, int v2, int v3)
{
    int max0 = max(v0,v1);
    int max1 = max(v2,v3);
    
    return max(max0, max1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, c, d;

    cin >> n >> a >> b >> c >> d;

    int v0 = a + b;
    int v1 = a + c;
    int v2 = b + d;
    int v3 = c + d;
    
    int minimum = getMin(v0, v1, v2, v3);
    int maximum = getMax(v0, v1, v2, v3);
    
    //debug3(minimum, maximum);
    
    int dif = maximum - minimum;
    
    if(dif > n)
    {
        cout <<"0\n";
        return 0;
    }
    
    dif = n - dif;
    
    //debug3(n, dif);
    
    int64 result = (int64)dif * (int64)n;
    
    cout << result << endl;
    
    return 0;
}
