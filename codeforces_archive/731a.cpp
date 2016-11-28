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

    char s[110];
    
    cin.getline(s, 109);    
    //strcpy(s, "zeus");
    
    int cur = 0;

    int len = 0;

    for(; s[len] != 0; ++len)
    {
        s[len] -= 'a';
    }

    int res = 0;

    for(int i=0; i < len; ++i)
    {
        int dif1 = abs(cur - s[i]);
        int dif2 = abs(cur + 26 - s[i]);
        int dif3 = abs(s[i] + 26 - cur);

        res += min(min(dif1, dif2), dif3);
        cur = s[i];
    }

    cout << res << endl;

    return 0;
}
