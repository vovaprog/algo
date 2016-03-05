#include <bits/stdc++.h>

using namespace std;

void debug(const char *format, ...)
{
    /*va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}

int mDays[370]={0};
int fDays[370]={0};

int main()
{
    int nFriends;
    
    cin >>nFriends;
    
    for(int i=0;i<nFriends;i++)
    {
        char gender;
        int firstDay, lastDay;
        
        cin >>gender>>firstDay>>lastDay;
        
        if(gender=='M')
        {
            for(int i=firstDay;i<=lastDay;++i)
            {
                mDays[i] += 1;    
            }
        }
        else
        {
            for(int i=firstDay;i<=lastDay;++i)
            {
                fDays[i] += 1;    
            }            
        } 
    }
    
    int max = 0;
    
    for(int i=1;i<=366;i++)
    {
        int count;
        
        if(mDays[i]<fDays[i])
        {
            count = mDays[i];    
        }
        else
        {
            count = fDays[i];    
        }
        
        if(count>max)
        {
            max = count;    
        }
    }
    
    cout << max*2 << endl;
        
    return 0;
}


