#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

set<int> t[1000000+10];
int d[1000000+10];
int parent[1000000+10];

int nRows, nCols;


inline int getIndex(int row, int col)
{
    return row * nCols + col;
}

inline int countryIndex(char code)
{
    return nRows * nCols+(code - '1');
}

int findRoads(int start)
{
    for(int i=0;i<nRows * nCols+3;i++) 
    {
        d[i]=-1;
        parent[i]=-1;
    }
    
    queue<int> q;
    set<int> path;
    set<int> reached;
    
    q.push(start);
    if(start<nRows * nCols)
    {
        //printf("1!!!!!!!!!!!!!!!!1!\n");
        //d[start]=1;
        path.insert(start);
    }

    d[start]=0;    
    
    debug("======================= %d",start);
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
     
        debug("%d %d",cur,d[cur]);        
        
        for(auto& link : t[cur])
        {
            debug("%d",link);
            
            if(d[link]<0)
            {
                d[link] = d[cur]+1;
                parent[link]=cur;
                q.push(link);
                //debug("%d",d[link]);
                
                if(link>=nRows * nCols)
                {
                    debug("%d %d",link,d[link]);
                    if(reached.count(link)==0)
                    {
                        reached.insert(link);
                        int c = link;                        
                        while(parent[c]!=start)
                        {
                            path.insert(parent[c]);
                            c=parent[c];
                        }                        
                    }                    
                    if(reached.size()>=3) // d[countryIndex('1')]>=0 && d[countryIndex('2')]>=0 && d[countryIndex('3')]>=0)
                    {
                        //return d[countryIndex('1')] + d[countryIndex('2')] + d[countryIndex('3')];
                        /*debug("path: %s","");
                        for(auto& p : path)
                        {
                            
                            debug("%d",p);
                        } */                       
                        return path.size();
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
                        t[getIndex(i,j)].insert(getIndex(i,j-1));
                    }
                    else if(s[j-1]>='1' && s[j-1]<='3')
                    {
                        t[getIndex(i,j)].insert(countryIndex(s[j-1]));                        
                    }
                }
                if(j<nCols-1)
                {
                    if(s[j+1]=='.')
                    {
                        t[getIndex(i,j)].insert(getIndex(i,j+1));
                    }
                    else if(s[j+1]>='1' && s[j+1]<='3')
                    {
                        t[getIndex(i,j)].insert(countryIndex(s[j+1]));
                    }                    
                }
                if(i>0)
                {
                    if(prevS[j]=='.')
                    {
                        t[getIndex(i-1,j)].insert(getIndex(i,j));                     
                        t[getIndex(i,j)].insert(getIndex(i-1,j));
                    }
                    else if(prevS[j]>='1' && prevS[j]<='2')
                    {
                        t[getIndex(i,j)].insert(countryIndex(prevS[j]));
                        t[countryIndex(prevS[j])].insert(getIndex(i,j));
                    }
                }                
            }
            else if(s[j]>='1' && s[j]<='3')
            {
                if(j>0)
                {
                    if(s[j-1]=='.')
                    {
                        t[countryIndex(s[j])].insert(getIndex(i,j-1));
                    }
                    else if(s[j-1]>='1' && s[j-1]<='3')
                    {
                        t[countryIndex(s[j])].insert(countryIndex(s[j-1]));                        
                    }
                }
                if(j<nCols-1)
                {
                    if(s[j+1]=='.')
                    {
                        t[countryIndex(s[j])].insert(getIndex(i,j+1));
                    }
                    else if(s[j+1]>='1' && s[j+1]<='3')
                    {
                        t[countryIndex(s[j])].insert(countryIndex(s[j+1]));
                    }                    
                }
                if(i>0)
                {
                    if(prevS[j]=='.')
                    {
                        t[getIndex(i-1,j)].insert(countryIndex(s[j]));                     
                        t[countryIndex(s[j])].insert(getIndex(i-1,j));
                    }
                    else if(prevS[j]>='1' && prevS[j]<='2')
                    {
                        t[countryIndex(s[j])].insert(countryIndex(prevS[j]));
                        t[countryIndex(prevS[j])].insert(countryIndex(s[j]));
                    }
                }                 
            }
        }
        
        strcpy(prevS,s);
    }
    
    int minResult = 2000000;
    
    for(int i=0;i<nRows*nCols+3;i++)
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

