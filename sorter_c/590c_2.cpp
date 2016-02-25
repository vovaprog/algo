#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

set<int> t[1000000+10];
int d[1000000+10][3];

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

void findRoads(int start, int country)
{    
    queue<int> q;
    
    q.push(start);

    d[start][country]=0;    
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(auto& link : t[cur])
        {
            if(link == cur) continue;
            
            int newD;
            
            if(link<totalCells)
            {
                newD = d[cur][country] + 1;
            }
            else
            {
                newD = d[cur][country];                
            }            

            if(d[link][country]<0 || newD < d[link][country])
            {
                d[link][country] = newD;
                q.push(link);
            }
        }        
    }
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
                    else if(prevS[j]>='1' && prevS[j]<='3')
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
                    else if(prevS[j]>='1' && prevS[j]<='3')
                    {
                        t[countryIndex(s[j])].insert(countryIndex(prevS[j]));
                        t[countryIndex(prevS[j])].insert(countryIndex(s[j]));
                    }
                }                 
            }
        }
        
        strcpy(prevS,s);
    }
    
    if(t[c1Index].count(c2Index)!=0 &&
        t[c2Index].count(c3Index)!=0 ||
        t[c1Index].count(c3Index)!=0 &&
        t[c3Index].count(c2Index)!=0 ||        
        t[c2Index].count(c1Index)!=0 &&
        t[c1Index].count(c3Index)!=0        
        )
    {
        printf("0");
        return 0;
    }
    
    for(int i=0;i<1000000+10;i++)
    {
        for(int j=0;j<3;j++)
        {
            d[i][j] = -1;
        }
    }
    
    findRoads(c1Index,0);
    findRoads(c2Index,1);
    findRoads(c3Index,2);
    
    int minSum = 2000000;
    
    for(int i=0;i<totalCells;i++)
    {                
        if(d[i][0]>=0 && d[i][1]>=0 && d[i][2]>=0)
        {
            int sum;
            if(i<totalCells)
            {
                --d[i][0];
                --d[i][1];
                --d[i][2];
                sum = d[i][0] + d[i][1] + d[i][2] + 1;
            }
            else
            {
                sum = d[i][0] + d[i][1] + d[i][2];
            }            
            
            if(sum < minSum)
            {
                minSum = sum;
            }
        }                    
    }
    
    if(minSum==2000000)
    {
        printf("-1");
    }
    else
    {
        printf("%d",minSum);
    }
    
    return 0;
}

