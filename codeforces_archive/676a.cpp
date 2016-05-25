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

    int n;

    cin >> n;

    int pos1 = 0, posN = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        
        if(a==1)
        {
            pos1 = i;
        }
        else if(a==n)
        {
            posN = i;    
        }
    }
        
    if(pos1 == 1 && posN == n ||
        pos1 == n && posN == 1)
    {
        cout << n - 1 << endl;    
    }
    else
    {
        if(pos1 == 1)
        {
            cout << n - 1 << endl;
        }
        else if(posN == 1)
        {
            cout << n - 1 <<endl;
        }
        else if(pos1 == n)
        {
            cout << n - 1 <<endl;
        }
        else if(posN == n)
        {
            cout << n - 1 <<endl;
        }
        else
        {
            int maxDif = 0;
            int dif = n - pos1;
            maxDif = dif; 

            dif = n - posN;            
            maxDif = max(dif, maxDif);
            
            dif = posN - 1;
            maxDif = max(dif, maxDif);
            
            dif = pos1 - 1;
            maxDif = max(dif, maxDif);
            
            cout << maxDif <<endl;
        }
    }
            
    return 0;
}
