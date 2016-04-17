#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Movie
{
    int l, r, v, index;
    bool operator<(const Movie &m) const
    {
        if(v<m.v)
        {
            return true;
        }
        else if(v>m.v)
        {
            return false;
        }
        else
        {
            if(r<m.r) return true;
            else if(r>m.r) return false;
            else
            {
                if(index<m.index)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
};

Movie movies[110];

int main()
{
    int nTests, n;
    
    scanf("%d",&nTests);

    for(int test=0;test<nTests;++test)
    {
        scanf("%d",&n);

        for(int i = 0; i < n; ++i)
        {
            scanf("%d",&movies[i].l);
            movies[i].index = i + 1;
        }
        
        for(int i = 0; i < n; ++i)
        {
            scanf("%d",&movies[i].r);
            movies[i].v = movies[i].l * movies[i].r;
        }

        sort(movies, movies+n);

        printf("%d\n",movies[n-1].index);
    }    
    
    return 0;
}
