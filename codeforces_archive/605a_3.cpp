#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

int a[100000];
//int d[100000];
//set<int> gt[100000];
//set<int> lt[100000];
//set<int> cts[100001];

template<class TMap,class TKey,class TValue>
inline bool tryGetValue(TMap &m, TKey key, TValue &u)
{
    auto it = m.find(key);
    if(it!=m.end())
    {
        u = it->second;
        return true;
    }
    return false;
}

int main()
{
    int n;
    
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("0");
        return 0;
    }
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
         
    map<int,int> m;
    int mx = 1;
    
    for (int i=0; i<n; i++) 
    {
        int v;
        if(tryGetValue(m,a[i]-1,v))
        {
            m[a[i]] = v+1;
            if(v+1>mx) mx=v+1;
        }
        else
        {
            m[a[i]] = 1;
        }
    }      
    
    int count = n - mx;
    
    printf("%d",count);
    
    return 0;
}
