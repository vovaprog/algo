#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

char s[100010];

set<string> suffs;
set<int,greater<int>> starts2;
set<int,greater<int>> starts3;

int main()
{
    scanf("%s",s);
    
    int len = strlen(s);
    
    if(len - 3>=5)
    {
        starts3.insert(len-3);
        starts2.insert(len-2);
    }
    else if(len - 2>=5)
    {
        starts2.insert(len-2);    
    }
    
    while(true)
    {
        if(!starts2.empty())
        {
            int cur = *starts2.begin();
            starts2.erase(cur);
            
            string second = string(s+cur,2);
                
            if(cur-2>=5)
            {
                string first = string(s+cur-2,2);
                
                
                
                if(second!=first)
                {
                    suffs.insert(second);
                    
                    if(cur - 3>=5)
                    {
                        starts3.insert(cur-3);
                        starts2.insert(cur-2);
                    }
                    else if(cur - 2>=5)
                    {
                        starts2.insert(cur-2);    
                    }
                }                
            }
            else
            {
                suffs.insert(second);    
            }
        }
        if(!starts3.empty())
        {
            int cur = *starts3.begin();
            starts3.erase(cur);
            
            string second = string(s+cur,3);
                
            if(cur-3>=5)
            {
                string first = string(s+cur-3,3);
                
                if(second!=first)
                {
                    suffs.insert(second);
                    
                    if(cur - 3>=5)
                    {
                        starts3.insert(cur-3);
                        starts2.insert(cur-2);
                    }
                    else if(cur - 2>=5)
                    {
                        starts2.insert(cur-2);    
                    }
                }                
            }
            else
            {
                suffs.insert(second);
                if(cur-2>=5)
                {
                    starts2.insert(cur-2);    
                }
            }
        }
        
        if(starts2.empty() && starts3.empty())
        {
            break;    
        }        
    }
    
    cout << suffs.size()<<endl;
    
    for(auto& suf : suffs)
    {
        cout <<suf<<"\n";    
    }
        
    return 0;
}
