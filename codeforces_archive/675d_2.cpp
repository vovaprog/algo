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
    
    Point(int index, int val): index(index), val(val) {}
    
    bool operator<(const Point &p) const
    {
        return val < p.val;
    }
};

set<Point> t;
int result[100010];

int main()
{    
    int n;

    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
    {        
        int x;

        scanf("%d",&x);

        if(i!=0)
        {
            Point px(i, x);
            
            auto itSmall = t.lower_bound(px);            
            auto itBig = t.upper_bound(px);
            
            if(itBig==t.end())
            {
                result[i] = t.rbegin()->val;
            }
            else
            {
                if(itSmall == t.begin())
                {
                    const Point &ptSmall = *itSmall;
                    result[i] = ptSmall.val;
                }
                else
                {
                    --itSmall;
                    const Point &ptSmall = *itSmall;
                    const Point &ptBig = *itBig;
                    
                    if(ptSmall.index>ptBig.index) result[i] = ptSmall.val;
                    else result[i] = ptBig.val;
                }
            }
        }
        
        t.emplace(i, x);
    }    
    
    for(int i=1;i<n;++i)
    {
        printf("%d ",result[i]);
    }
    
    printf("\n");
    
    return 0;
}
