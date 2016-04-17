#include <bits/stdc++.h>

using namespace std;

//#define debug(args...) printf(args);
//#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int getH(int val)
{
    int count = 0;
    while(val)
    {
        val <<= 1;
        ++count;
    }

    return count;
}

int getH2(int b, int e)
{
    int eCount=0;

    while(true)
    {
        if(b>e)
        {
            b /= 2;
        }
        else if(b<e)
        {
            e/=2;
            ++eCount;
        }
        else
        {
            return eCount;
        }
    }
}

int countAll(int level)
{
    int result = 0;
    int b = 1;
    for(int i=0;i<level;++i)
    {
        result += b;
        b *= 2;
    }
    return result;
}

int stepUp(int n,int steps)
{
    for(int i=0;i<steps;++i)
    {
        n /= 2;
    }
    return n;
}

int firstValueOfLevel(int level)
{
    int b = 1;
    for(int i=0;i<level;++i)
    {
        b *= 2;
    }
    return b;    
}

int main()
{
    int nTests;
    
    cin >> nTests;

    for(int tst=0;tst<nTests;++tst)
    {
        int n,b,e;
        
        cin >>n>>b>>e;
        
        if(b>e) swap(b,e);
    
        int nH = getH(n);
        int beH = getH2(b,e);

        int levelCountAll = nH - beH;

        int result = 0;

        result += countAll(levelCountAll);

        int val = stepUp(n,beH);

        result += val - firstValueOfLevel(levelCountAll+1);

        if(e % 2 == n % 2)//repeatHistory(n,val))
        {
            result += 1;
        }
    
        /*cout <<result<<endl;*/
        cout <<tst<<" ";
    }    
    
    return 0;
}
