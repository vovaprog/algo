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

int64 pots[100100];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int64 n, hComb, kPotSec;

    cin >> n >> hComb >> kPotSec;

    for(int i = 0; i < n; ++i)
    {
        cin >> pots[i];
    }

    int64 hCur = 0, seconds = 0, curPot = 0, addSeconds;
    
    while(true)
    {
        for(;curPot < n;++curPot)
        {
            if(hCur + pots[curPot]<=hComb)
            {
                hCur += pots[curPot];    
            }
            else
            {
                break;    
            }
        }        
        if(hCur > kPotSec)
        {
            addSeconds = hCur / kPotSec;
            hCur = hCur % kPotSec;
            
            seconds += addSeconds;
        }
        else
        {
            hCur = 0;
            
            ++seconds;
        }        
        
        if(curPot >=n && hCur ==0)
        {
            break;    
        }
    }    
    
    cout << seconds << endl;
    
    return 0;
}