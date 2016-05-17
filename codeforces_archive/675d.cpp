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
    int result;
    int childSmall, childBig;    
};

Point points[100100];

void push(int index, int x)
{
    points[index].val = x;
    
    if(index == 0) return;
    
    int cur = 0, prevValue = 0;
    
    while(true)
    {
        if(x < points[cur].val)
        {
            if(points[cur].childSmall<0)
            {
                points[cur].childSmall = index;
                points[index].result = points[cur].val;
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
                points[index].result = points[cur].val;
                return;
            }
            else
            {
                cur = points[cur].childBig;    
            }                        
        }        
    }
}


int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    
    for(int i=0;i<100010;i++)
    {
        points[i].val = -1;
        points[i].result = -1;
        points[i].childSmall = -1;
        points[i].childBig = -1;
    }
    
    int n;

    //cin >> n;
    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
    {        
        int x;
        //cin >> x;
        scanf("%d",&x);
        push(i, x);
    }    
    
    for(int i=1;i<n;++i)
    {
        printf("%d ",points[i].result);
        //cout <<points[i].result<<" ";
    }
    
    //cout <<endl;
    printf("\n");
    
    return 0;
}
