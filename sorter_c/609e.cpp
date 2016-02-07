#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

struct Edge{
    int v0,v1;
    int weight;
    int number;
    long long int result;
};

struct Node{    
    int parent;
    int depth;    
    vector<int> links;
};


int vCount;

int minNode=2000000000;
int maxNode=0;

vector<Edge> tree;

Node nodes[200001];
Edge edges[200001];

long long int results[200001];

int dp[200001][19]={0};
int dpWeight[200001][19]={0};

int p[200001], rankCount[200001];


void initSet()
{
    for(int i=0;i<=200001;i++)
    {
        p[i] = i;
        rankCount[i] = 0;
    }
}


int find(int x) 
{    
    return ( x == p[x] ? x : p[x] = find(p[x]) );    
}


void unite(int x, int y) 
{
    if ( (x = find(x)) == (y = find(y)) )
        return;
    
    if ( rankCount[x] <  rankCount[y] )
        p[x] = y;
    else
        p[y] = x;

    if ( rankCount[x] == rankCount[y] )
        ++rankCount[x];    
}


void walkTree(int cur, int parent,int depth)
{
    Node &curNode = nodes[cur];
    
    curNode.depth = depth;
    curNode.parent = parent;
    
    int linksSize = curNode.links.size();
    int newDepth = depth+1;
    
    for(int i=0;i<linksSize;i++)
    {
        int linksI = curNode.links[i];
        
        if(tree[linksI].v0!=cur && linksI!=parent)
        {
            walkTree(tree[linksI].v0, linksI, newDepth);
        }
        else if(tree[linksI].v1!=cur && linksI!=parent)
        {
            walkTree(tree[linksI].v1, linksI, newDepth);
        }
    }
}


int compareEdge( const void* al0, const void* al1)
{
    return ((Edge*)al1)->weight - ((Edge*)al0)->weight;    
}


inline int mylog2(int value)
{
    int counter = 0;
    
    while(true)
    {
        value = value >> 1;
        if(value!=0)
        {
            ++counter;    
        }
        else break;
    }
    
    return counter;
}

void lcaPreprocess()
{
    int treeSize = tree.size();
    
    for(int i=minNode;i<=maxNode;i++)
    {
        if(nodes[i].links.size()>0)
        {
            int parentNode;
            
            if(nodes[i].parent>=0)
            {            
                Edge &e = tree[nodes[i].parent];
                
                if(e.v0 == i) parentNode = e.v1;
                else parentNode = e.v0;    
                
                dp[i][0] = parentNode;
                dpWeight[i][0] = e.weight;
            }
            else
            {
                dp[i][0] = i;
                dpWeight[i][0] = 0;
            }
        }
    }
        
    int logValue = mylog2(treeSize);
        
    for(int j=1;j<=logValue;j++)        
    {
        for(int i=minNode;i<=maxNode;i++)
        {
            if(nodes[i].links.size()>0)
            {
                int weightPrev = dpWeight[i][j-1];
                int weightNext = dpWeight[ dp[i][j - 1] ]   [j - 1];                            
                
                if(weightPrev > weightNext ) dpWeight[i][j] = weightPrev;
                else dpWeight[i][j] = weightNext;
                
                dp[i][j] = dp[ dp[i][j - 1] ]   [j - 1];    
            }
        }
    }
}

int lcaFindMaxWeight(int v, int u)
{
    if(nodes[v].depth > nodes[u].depth)
    {
        int temp = v;
        v = u;
        u = temp;
    }

    int logValue = mylog2(tree.size()); 
    
    int maxWeight = 0;
    
    if(nodes[u].depth!=nodes[v].depth)
    {
        for(int i = logValue;i>=0;i--)
        {
            if(nodes[u].depth - nodes[v].depth>=(1<<i))
            {
                if(dpWeight[u][i]>maxWeight)
                {
                    maxWeight = dpWeight[u][i];
                }
           
                u=dp[u][i];
            }
        }
    }
    
    if(u==v) return maxWeight;
    
    int i;
    for(i = logValue;i>=0;--i)
    {
        if(dp[v][i]!=dp[u][i])
        {
            if(dpWeight[u][i]>maxWeight)
            {
                maxWeight = dpWeight[u][i];  
            }
            if(dpWeight[v][i]>maxWeight)
            {
                maxWeight = dpWeight[v][i];   
            }                        
            v = dp[v][i];
            u = dp[u][i];
            
            if(u==v)
            {
                return maxWeight;    
            }
        }
    }
        
    if(dpWeight[v][0]>maxWeight)        
    {
        maxWeight = dpWeight[v][0];    
    }
    if(dpWeight[u][0]>maxWeight)        
    {
        maxWeight = dpWeight[u][0];    
    }

    return maxWeight;   
}

int main()
{
    int eCount;
    
    initSet();
    
    scanf("%d %d",&vCount, &eCount);
    
    if(eCount<1)
    {
        return 0;    
    }    
    
    for(int i=0;i<eCount;i++)
    {
        Edge &e = edges[i];
        e.number = i+1;
        scanf("%d %d %d",&e.v0, &e.v1, &e.weight);

        if(e.v0<minNode)
        {
            minNode = e.v0;    
        }        
        if(e.v0>maxNode)
        {
            maxNode = e.v0;    
        }
        
        if(e.v1<minNode)
        {
            minNode = e.v1;    
        }        
        if(e.v1>maxNode)
        {
            maxNode = e.v1;    
        }        
    }
    
    qsort( edges, eCount, sizeof(Edge), compareEdge );
    
    vector<Edge> bigs;
    
    bigs.reserve(200001);
    tree.reserve(200001);
    
    for(int i=eCount-1;i>=0;--i)
    {
        Edge &e = edges[i];
        
        int foundNumber0 = find(e.v0);
        int foundNumber1 = find(e.v1);
        
        if(foundNumber0!=foundNumber1)
        {
            unite(e.v0, e.v1);
                        
            tree.push_back(e);
            
            nodes[e.v0].links.push_back(tree.size()-1);
            nodes[e.v1].links.push_back(tree.size()-1);        
        }
        else
        {
            bigs.push_back(e);
        }        
    }        
    
    long long int treeResult = 0;
        
    for(auto& e : tree)
    {                
        treeResult += e.weight;
    }
    
    for(auto& e : tree)
    {
        results[e.number] = treeResult;
    }
    
    
    walkTree(minNode, -1, 0);

        
    lcaPreprocess();

    for(auto &e : bigs)
    {
        int maxWeight = lcaFindMaxWeight(e.v0,e.v1);
        
        results[e.number] = treeResult - maxWeight + e.weight;
    }
            
    for(int i=1;i<=eCount;i++)
    {
        cout <<results[i]<<endl;    
    }
    
    return 0;    
}
