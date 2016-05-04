#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

char s[100010];

struct Suffix{
    char letters[4];
    
    Suffix(int start, int take)
    {
        letters[0] = s[start];
        letters[1] = s[start+1];
        if(take==3)
        {
            letters[2] = s[start+2];
            letters[3] = 0;
        }
        else
        {
            letters[2] = 0;    
        }        
    }
    
    inline bool operator<(const Suffix &s) const
    {
        int val0 = ((int)letters[0] << 16) + 
            ((int)letters[1] << 8) + (int)letters[2];

        int val1 = ((int)s.letters[0] << 16) + 
            ((int)s.letters[1] << 8) + (int)s.letters[2];
        
        return val0 < val1;
    }
    
    inline operator const char*() const
    {
        return letters;    
    }
};

set<Suffix> suffs;

bool equal(int start0, int count0, int start1, int count1)
{
    if(count0!=count1) return false;
    
    if(count0==2)
    {
        if(s[start0]==s[start1] && s[start0+1]==s[start1+1])
        {
            return true;    
        }
        else
        {
            return false;    
        }        
    }
    else
    {
        if(s[start0]==s[start1] && 
            s[start0+1]==s[start1+1] &&
            s[start0+2]==s[start1+2])
        {
            return true;    
        }
        else
        {
            return false;    
        }        
    }        
}

struct HistoryEntry{
    int start, take, prevTake;
    
    HistoryEntry(int start,int take,int prevTake):start(start),
        take(take),prevTake(prevTake){}
    
    bool operator<(const HistoryEntry &ent) const
    {
        if(start<ent.start) return true;
        else if(start>ent.start) return false;
        else
        {
            if(take<ent.take) return true;
            else if(take>ent.take) return false;
            else
            {
                if(prevTake<ent.prevTake) return true;
                else if(prevTake>ent.prevTake) return false;
            }
        }
        return false;
    }
};

set<HistoryEntry> history;

inline void parse(int start, int take, int prevTake)
{
    if(prevTake>0)
    {
        if(equal(start,take,start + take,prevTake))
        {
            return;
        }
    }
    
    suffs.emplace(start,take);
    
    history.emplace(start,take,prevTake);
    
    if(start-2>=5)
    {
        HistoryEntry ent(start - 2, 2, take);
        if(history.count(ent)==0)
        {
            parse(start - 2, 2, take);
        }
    }
    if(start-3>=5)
    {
        HistoryEntry ent(start - 3, 3, take);
        if(history.count(ent)==0)
        {
            parse(start - 3, 3, take);
        }
    }
}



int main()
{
    scanf("%s",s);
    
    int len = strlen(s);
    
    if(len-2>=5)
    {
        parse(len-2, 2, -1);
    }
    if(len-3>=5)
    {
        parse(len-3, 3, -1);
    }
    
    cout << suffs.size()<<endl;
    
    for(auto& suf : suffs)
    {
        cout <<suf<<"\n";
    }
    
    return 0;
}
