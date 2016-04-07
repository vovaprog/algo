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

struct Field{
    vector<Stog> sts;    
};

template<class TMap,class TKey,class TValue>
inline bool tryGetValue(TMap &m, TKey &key, TValue &u)
{
    auto it = m.find(key);
    if(it!=m.end())
    {
        u = it->second;
        return true;
    }
    return false;
}

vector<Field> fs;

int nRows,nCols,k;

map<int,int> fsMap;

int findField(int r,int c)
{        
    int ind;
    
    if(r>0)
    {
        int h = (r-1)*nCols+c;
        debug2("1>>> %d",h);
        if(tryGetValue(fsMap,h,ind))
        {
            return ind;
        }
    }
    if(c<nCols-1)
    {
        int h = r*nCols+c+1;
        debug2("2>>> %d",h);
        if(tryGetValue(fsMap,h,ind))
        {
            return ind;
        }        
    }
    if(r<nRows-1)
    {
        int h = (r+1)*nCols+c;
        debug2("3>>> %d",h);
        if(tryGetValue(fsMap,h,ind))
        {
            return ind;
        }        
    }
    if(c>0)
    {
        int h = r*nCols+c-1;
        debug2("4>>> %d",h);
        if(tryGetValue(fsMap,h,ind))
        {
            return ind;
        }        
    }
    
    return -1;
}

int result[1010][1010]={0};

bool calcResult(int fsIndex)
{
    vector<Stog> &sts = fs[fsIndex].sts;
    Stog &st = sts[sts.size()-1];
    
    if(k % st.val!=0)
    {
        debug("ret 1\n");
        return false;
    }
 
    int neededCount = k / st.val;
    
    int stsSize = sts.size();
    
    if(stsSize<neededCount) 
    {
        debug("ret 2: %d %d\n",stsSize,neededCount);
        return false;
    }
    
    for(int i=stsSize-1;i>=0 && neededCount>=0;--i,--neededCount)
    {
        Stog &s = sts[i];
        result[s.r][s.c] = st.val;
    }
    
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
    
    
    scanf("%d%d%d",&nRows,&nCols,&k);
    
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
    
    for(auto &st : sts)
    {        
        int fsIndex = findField(st.r,st.c);
        if(fsIndex<0)
        {
            debug("fsIndex<0\n");
            Field f;
            fs.push_back(f);
            fsIndex = fs.size()-1;
        }
        debug2("%d",fsIndex);
        fs[fsIndex].sts.push_back(st);
        debug2("----------- %d %d",fsIndex,fs[fsIndex].sts.size());
        fsMap[st.r*nCols+st.c] = fsIndex;
        debug2("%d %d",st.r*nCols+st.c,fsIndex);
        
        if(calcResult(fsIndex))
        {
            return 0;
        }
    }
    
    printf("NO\n");
    
    return 0;
}
