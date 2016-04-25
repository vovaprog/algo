#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int64 dirs[100010]={0};
int64 lens[100010]={0};
int64 visited[100010]={0};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    int64 n;
    
    cin >> n;
    
    for(int i = 0; i < n; ++i)
    {
        char dir;
        
        cin >> dir;
        if(dir=='<')
        {
            dirs[i] = -1;
        }
        else
        {
            dirs[i] = 1;
        }
    }
    
    for(int i = 0;i<n;++i)
    {
        cin >> lens[i];
    }
    
    int64 cur = 0;
    
    while(true)
    {
        visited[cur] = 1;
        cur += lens[cur] * dirs[cur];
        if(cur < 0 || cur>=n)
        {
            cout <<"FINITE"<<endl;
            return 0;
        }
        if(visited[cur]!=0)
        {
            cout <<"INFINITE"<<endl;
            return 0;
        }        
    }        
    
    return 0;
}
