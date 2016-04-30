#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

//set<string> suffs;

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
    
    bool operator<(const Suffix &s) const
    {
        if(letters[0]<s.letters[0]) return true;
        else if(letters[0]>s.letters[0]) return false;
        else
        {
            if(letters[1]<s.letters[1]) return true;
            else if(letters[1]>s.letters[1]) return false;
            else
            {
                if(letters[2]<s.letters[2]) return true;
                else if(letters[2]>s.letters[2]) return false;                
            }                
        }
        
        return false;
    }
    
    /*operator char*() const
    {
        return letters;    
    }*/
    
    const char* toCharPointer() const
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

void parse(int start, int take, int prevTake)
{
    if(prevTake>0)
    {
        if(equal(start,take,start + take,prevTake))
        {
            return;
        }
    }
    
    //suffs.insert(string(s+start,take));
    suffs.insert(Suffix(start,take));
    
    if(start-2>=5)
    {
        parse(start - 2, 2, take);
    }
    if(start-3>=5)
    {
        parse(start - 3, 3, take);   
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
        //cout <<(char*)suf<<"\n";
        
        cout <<suf.toCharPointer()<<"\n";
    }
    
    return 0;
}
