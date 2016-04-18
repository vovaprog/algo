#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

vector<int> histE;

int createHistory(int b, int e)
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

int n;

bool repeatHistory(int v)
{
    int64 x = v;
    for(int i=histE.size()-1;i>=0;--i)
    {
        x *= 2;
        if(histE[i]) 
        {   
            x+=1;
        }
    }    
    return x<=n;
}

//==================================================================================
//Бинарный поиск последнего значения, для которого функция check вернет true
//==================================================================================

typedef bool (*checkValue)(int v);

int binarySearchLastTrue(int b, int e, checkValue check)
{
    int lastTrue = -1;

    while(true)
    {
        int v = b + (e - b) / 2;

        if(check(v))
        {
            lastTrue = v;
            b = v+1;                    
        }
        else
        {
            e = v-1;
        }

        if(b > e)
        {
            return lastTrue;
        }
    }
}

//==================================================================================
//==================================================================================


int main()
{
    int nTests;
    
    scanf("%d",&nTests);

    for(int test=0;test<nTests;++test)
    {
        int begin, end;
        
        scanf("%d%d%d",&n,&begin,&end);
        
        if(begin==end)
        {
            printf("%d\n",n);            
        }
        else
        {
            if(begin>end) swap(begin,end);

            createHistory(begin,end);

            int v = binarySearchLastTrue(1, n, repeatHistory);

            printf("%d\n", v);
        }
    }    
    
    return 0;
}

