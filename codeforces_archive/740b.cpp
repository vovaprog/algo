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

/*struct Sub{
    int start, end;
    bool operator<(const Sub &s)
    {
        return start < s.start;
    }
};*/

bool compSub(const pair<int,int> &p1, const pair<int,int> &p2)
{
    return p1.start < p2.start;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
   
    int nFlowers, nSubs;

    cin >> nFlowers >> nSubs;

    vector<int> flowers;
    flowers.reserve(nFlowers);

    for(int i = 0; i < nFlowers; ++i)
    {
        int f;
        cin >> f;
        flowers.push_back(f);
    }

    vector<pair<int,int>> subs;
    subs.reserve(nSubs);

    for(int i=0; i< nSubs; ++i)
    {
        int s, e;
        cin >> s >> e;
        subs.emplace_back(s,e);
    }
    
    sort(subs.begin(), subs.end(), compSub);

    for(int i=0;i < nFlowers;++i)
    {
        if(i>=subStarts[curSubStarts])
        {
            curSubs.insert(
        }
    }

    return 0;
}
