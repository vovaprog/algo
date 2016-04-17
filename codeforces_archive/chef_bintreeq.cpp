#include <bits/stdc++.h>

using namespace std;

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int getH(int val)
{
    int count = 0;
    while(val)
    {
        val >>= 1;
        ++count;
    }

    return count;
}

vector<int> histE;

int getH2(int b, int e)
{
    histE.clear();

    int eCount=1;

    while(true)
    {
        if(b>e)
        {
            b /= 2;            
        }
        else if(b<e)
        {
            if(e % 2==0) histE.push_back(0);
            else histE.push_back(1);

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
    for(int i=0;i<level-1;++i)
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
        
        cin >>n;
        cin >>b;
        cin >>e;

        if(b==e)
        {
            cout <<n<<endl;
        }
        else
        {
            if(b>e) swap(b,e);

            int nH = getH(n);
            int beH = getH2(b,e);

            int levelCountAll = nH - beH;

            int result = 0;

            result += countAll(levelCountAll);

            int val = stepUp(n,beH - 1);

            int firstValue = firstValueOfLevel(levelCountAll+1);

            result += val - firstValueOfLevel(levelCountAll+1);

            int x = val;

            for(int i=histE.size()-1;i>=0;--i)
            {
                x *= 2;
                if(histE[i]) 
                {   
                    x+=1;
                }
            }

            if(x<=n) 
            {
                ++result;
            }

            cout <<result<<endl;
        }
    }    
    
    return 0;
}
