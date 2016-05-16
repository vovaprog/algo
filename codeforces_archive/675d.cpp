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
    int val;
    int index;
    int childSmall, childBig;    
};

Point points[100100];

int a[100100];
int pos[100100];
int result[100100];

void push(int index, int x)
{
    points[index].val = x;
    
    if(index == 0) return;
    
    int cur = 0;
    
    while(true)
    {
        if(x < points[cur].val)
        {
            if(points[cur].childSmall<0)
            {
                points[cur].childSmall = index;
                return;
            }
            else
            {
                cur = points[cur].childSmall;    
            }
        }
        else
        {
            if(points[cur].childBig<0)
            {
                points[cur].childBig = index;
                return;
            }
            else
            {
                cur = points[cur].childBig;    
            }                        
        }        
    }
}

void walk(int cur, int parentValue)
{
    result[cur] = parentValue;
    
    if(points[cur].childSmall>=0)
    {
        walk(points[cur].childSmall, points[cur].val);    
    }
    if(points[cur].childBig>=0)
    {
        walk(points[cur].childBig, points[cur].val);    
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<100010;i++)
    {
        points[i].val = -1;
        points[i].childSmall = -1;
        points[i].childBig = -1;
    }
    
    int n;

    cin >> n;

    for(int i = 0; i < n; ++i)
    {        
        int x;
        cin >> x;
        push(i, x);
    }
    
    walk(0, -1);
    
    for(int i=0;i<n;++i)
    {
        if(result[i]>=0)
        {
            cout <<result[i]<<" ";
        }
    }
    
    cout <<endl;
    
    return 0;
}
