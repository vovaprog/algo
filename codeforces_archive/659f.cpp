#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Stog{
    int r,c,val;
    bool operator>(const Stog &st) const
    {
        return val>st.val;
    }
};

int nRows,nCols;
int64 k;

bool visited[1000010]={false};
int result[1010][1010]={0};
bool dfsVisited[1010][1010]={false};


//==========================================================================
//Система непересекающихся множеств
//Disjoint-set data structure
//==========================================================================

const int djItemCount = 1000010;
int p[djItemCount];
int64 s[djItemCount]; //дополнение

void djInit()
{
    iota(p, p+djItemCount, 0);    
}

int djFind(int x) 
{
    if(p[x]==x)
    {
        return x;
    }
    else
    {
        p[x] = djFind(p[x]);
        return p[x];
    }
}

void djUnite(int x, int y) 
{
    int fx = djFind(x);
    int fy = djFind(y);
    
    if(fx == fy)
    {
        return;
    }

    s[fy] = s[fx] + s[fy]; //дополнение
    
    p[fx] = fy;    
}

//==========================================================================
//==========================================================================
//==========================================================================


inline int getId(int r, int c)
{
    return r*nCols + c;
}

int checkAdjacent(int r,int c)
{        
    int id = getId(r,c);
    
    if(r>0)
    {
        int h = getId(r-1,c);
        if(visited[h]) djUnite(id,h);
    }
    if(c<nCols-1)
    {
        int h = getId(r,c+1);
        if(visited[h]) djUnite(id,h);        
    }
    if(r<nRows-1)
    {
        int h = getId(r+1,c);
        if(visited[h]) djUnite(id,h);        
    }
    if(c>0)
    {
        int h = getId(r,c-1);
        if(visited[h]) djUnite(id,h);        
    }
}

int dfs(int r,int c,int need,int val)
{
    dfsVisited[r][c] = true;
    result[r][c]=val;
    --need;
    
    if(r>0 && need>0)
    {
        if(!dfsVisited[r-1][c] && visited[getId(r-1,c)])
        {
            need = dfs(r-1,c,need,val);
        }
    }
    if(c<nCols-1 && need>0)
    {
        if(!dfsVisited[r][c+1] && visited[getId(r,c+1)])
        {
            need = dfs(r,c+1,need,val);
        }
    }
    if(r<nRows-1 && need>0)
    {
        if(!dfsVisited[r+1][c] && visited[getId(r+1,c)])
        {
            need = dfs(r+1,c,need,val);
        }
    }
    if(c>0 && need>0)
    {
        if(!dfsVisited[r][c-1] && visited[getId(r,c-1)])
        {
            need = dfs(r,c-1,need,val);
        }
    }
    
    return need;
}

bool calcResult(Stog &st)
{
    dfs(st.r,st.c,k/st.val,st.val);
    
    printf("YES\n");
    
    for(int i=0;i<nRows;++i)
    {
        for(int j=0;j<nCols;++j)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    djInit();
    
    scanf("%d%d%I64d",&nRows,&nCols,&k);
    
    vector<Stog> sts;
    sts.reserve(nRows*nCols);
    
    for(int i = 0; i < nRows; ++i)
    {
        for(int j=0;j<nCols;++j)
        {
            Stog st;
            st.r = i;
            st.c = j;
            scanf("%d",&st.val);
            sts.push_back(st);
        }
    }
    
    sort(sts.begin(),sts.end(),greater<Stog>());
    
    fill(s, s+djItemCount, 1);
    
    for(auto &st : sts)
    {
        int id = getId(st.r,st.c);
        visited[id] = true;
        
        checkAdjacent(st.r,st.c);
        if(k % st.val==0)
        {
            int64 sm = s[djFind(id)];
            
            if(sm>=k/st.val)
            {
                calcResult(st);
                return 0;
            }
        }        
    }
    
    printf("NO\n");
    
    return 0;
}


