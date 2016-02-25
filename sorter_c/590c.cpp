#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

//set<int> t[1000000+10];
vector<int> t[1000000+10];
int d[1000000+10];
//int parent[1000000+10];

int nRows, nCols;
int totalCells;
int c1Index,c2Index,c3Index;


inline int getIndex(int row, int col)
{
    return row * nCols + col;
}

inline int countryIndex(char code)
{
    return totalCells+(code - '1');
}

deque<int> q;
//queue<int> q;

int findRoads(int start)
{
    memset(d,-1,sizeof(int)*(totalCells+5));
    
    /*for(int i=0;i<totalCells+3;i++) 
    {
        d[i]=-1;
    }*/
    
    q.clear();
    //q = {};
    
    q.push_back(start);
    //q.push(start);

    d[start]=0;    
    
    debug("======================= %d",start);
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop_front();
        //q.pop();
     
        debug("%d %d",cur,d[cur]);        
        
        for(auto& link : t[cur])
        {
            debug("%d",link);
            
            if(d[link]<0)
            {
                d[link] = d[cur]+1;
                q.push_back(link);
                //q.push(link);
                //debug("%d",d[link]);
                
                if(link>=nRows * nCols)
                {
                    debug("%d %d",link,d[link]);
                    
                    if(d[c1Index]>=0 && d[c2Index]>=0 && d[c3Index]>=0)
                    {
                        return d[c1Index] + d[c2Index] + d[c3Index] - 2;
                    }
                }
            }
        }        
    }
    
    return -1;
}

int main()
{    
    char s[1001],prevS[1001];
    
    scanf("%d %d",&nRows, &nCols);
    
    totalCells = nRows * nCols;
    c1Index = countryIndex('1');
    c2Index = countryIndex('2');
    c3Index = countryIndex('3');
    
    for(int i=0;i<nRows;i++)
    {
        scanf("%s",s);
        
        for(int j=0;j<nCols;j++)
        {
            if(s[j]=='.')
            {
                if(j>0)
                {
                    if(s[j-1]=='.')
                    {
                        t[getIndex(i,j)].push_back(getIndex(i,j-1));
                    }
                    else if(s[j-1]>='1' && s[j-1]<='3')
                    {
                        t[getIndex(i,j)].push_back(countryIndex(s[j-1]));                        
                    }
                }
                if(j<nCols-1)
                {
                    if(s[j+1]=='.')
                    {
                        t[getIndex(i,j)].push_back(getIndex(i,j+1));
                    }
                    else if(s[j+1]>='1' && s[j+1]<='3')
                    {
                        t[getIndex(i,j)].push_back(countryIndex(s[j+1]));
                    }                    
                }
                if(i>0)
                {
                    if(prevS[j]=='.')
                    {
                        t[getIndex(i-1,j)].push_back(getIndex(i,j));                     
                        t[getIndex(i,j)].push_back(getIndex(i-1,j));
                    }
                    else if(prevS[j]>='1' && prevS[j]<='2')
                    {
                        t[getIndex(i,j)].push_back(countryIndex(prevS[j]));
                        t[countryIndex(prevS[j])].push_back(getIndex(i,j));
                    }
                }                
            }
            else if(s[j]>='1' && s[j]<='3')
            {
                if(j>0)
                {
                    if(s[j-1]=='.')
                    {
                        t[countryIndex(s[j])].push_back(getIndex(i,j-1));
                    }
                    else if(s[j-1]>='1' && s[j-1]<='3')
                    {
                        t[countryIndex(s[j])].push_back(countryIndex(s[j-1]));                        
                    }
                }
                if(j<nCols-1)
                {
                    if(s[j+1]=='.')
                    {
                        t[countryIndex(s[j])].push_back(getIndex(i,j+1));
                    }
                    else if(s[j+1]>='1' && s[j+1]<='3')
                    {
                        t[countryIndex(s[j])].push_back(countryIndex(s[j+1]));
                    }                    
                }
                if(i>0)
                {
                    if(prevS[j]=='.')
                    {
                        t[getIndex(i-1,j)].push_back(countryIndex(s[j]));                     
                        t[countryIndex(s[j])].push_back(getIndex(i-1,j));
                    }
                    else if(prevS[j]>='1' && prevS[j]<='2')
                    {
                        t[countryIndex(s[j])].push_back(countryIndex(prevS[j]));
                        t[countryIndex(prevS[j])].push_back(countryIndex(s[j]));
                    }
                }                 
            }
        }
        
        strcpy(prevS,s);
    }
    
    int minResult = 2000000;
    
    for(int i=0;i<totalCells+3;i++)
    {
        if(t[i].size()>0)
        {
            int result = findRoads(i);
            debug("%d",result);
            if(result>=0 && result<minResult)
            {
                minResult = result;
            }
        }        
    }
    
    if(minResult==2000000)
    {
        printf("-1");
    }
    else
    {
        printf("%d",minResult);
    }
    
    return 0;
}

