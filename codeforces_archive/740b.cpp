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

struct Sub{
    int start, end, index, value = 0;
};

bool compSubStarts(Sub *p1, Sub *p2)
{
    if(p1->start < p2->start) return true;
    if(p1->start > p2->start) return false;
    return p1->end < p2->end;
}

bool compSubEnds(Sub *p1, Sub *p2)
{
    return p1->end < p2->end;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
   
    int nFlowers, nSubs;

    istringstream ss("5 4\n1 -2 1 3 -4\n1 2\n4 5\n3 4\n1 4\n");
    ss >> nFlowers >> nSubs;

    vector<int> flowers;
    flowers.reserve(nFlowers);

    for(int i = 0; i < nFlowers; ++i)
    {
        int f;
        ss >> f;
        flowers.push_back(f);
    }

    Sub subs[110];
    vector<Sub*> subStarts, subEnds;
    subStarts.reserve(nSubs);
    subEnds.reserve(nSubs);

    for(int i=0; i< nSubs; ++i)
    {
        ss >> subs[i].start >> subs[i].end;
        subs[i].index = i + 1;
        subStarts.push_back(&subs[i]);
        subEnds.push_back(&subs[i]);
    }
    
    sort(subStarts.begin(), subStarts.end(), compSubStarts);
    sort(subEnds.begin(), subEnds.end(), compSubEnds); 

    set<int> curSubs;
    int curSubStarts = 0, curSubEnds = 0;

    for(int i=1;i <= nFlowers;++i)
    {
        while(curSubStarts < nSubsi>=subStarts[curSubStarts]->start && )
        {
            curSubs.insert(subStarts[curSubStarts]->index);
            ++curSubStarts;
        }
        while(i>subEnds[curSubEnds]->end && curSubEnds < nSubs)
        {
            curSubs.erase(subEnds[curSubEnds]->index);
            ++curSubEnds;
        }
        for(int subIndex : curSubs)
        {
            subs[subIndex - 1].value += flowers[i - 1];
        }
    }

    int sum = 0;

    for(Sub &s : subs)
    {
        if(s.value > 0)
        {
            sum += s.value;
        }
    }

    cout << sum << endl;

    return 0;
}


