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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    int64 x;

    cin >> x;

    const int64 a1000 = 1234567, b100 = 123456, c10 = 1234;
        
    for(int64 a=0;a<=x;a+=a1000)
    {                
        for(int64 b=0;a+b<=x;b+=b100)
        {
            if((x - a - b) % c10 == 0)
            {
                cout << "YES"<<endl;
                return 0;                
            }
        }
    }

    cout << "NO" <<endl;
    
    return 0;
}
