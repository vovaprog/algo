#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

set<string> suffs;

void parse(string &s, string &prev, int start, int take)
{
    string cur = s.substr(start,take);
    
    if(cur!=prev)
    {
        suffs.insert(cur);
        
        if(start-2>=5)
        {
            parse(s, cur, start - 2, 2);
        }
        if(start-3>=5)
        {
            parse(s,cur, start - 3, 3);   
        }
    }
}

int main()
{
    string s, empty;
    
    cin >> s;
    
    int sz = s.size();
    
    if(sz-2>=5)
    {
        parse(s, empty, sz-2, 2);
    }
    if(sz-3>=5)
    {
        parse(s, empty, sz-3, 3);
    }
    
    cout << suffs.size()<<endl;
    
    for(auto& suf : suffs)
    {
        cout <<suf<<"\n";    
    }
    
    return 0;
}
