#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
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

int dp[200001][18]={0};
int dpWeight[200001][18]={0};


/*
inline int findMaxWeight(int n0, int n1)
{
    int maxWeight = 0;
    
    int depthDif = nodes[n0].depth - nodes[n1].depth;
    
    for(int i=0;i<depthDif;i++)
    {
        Edge &e = tree[nodes[n0].parent];
        
        int curWeight = e.weight;
        
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;            
        }        
        
        if(e.v0 == n0) n0 = e.v1;
        else n0 = e.v0;
    }
    
    for(int i=0;i<-depthDif;i++)
    {
        Edge &e = tree[nodes[n1].parent];
        
        int curWeight = e.weight;
        
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;    
        }        
        
        if(e.v0 == n1) n1 = e.v1;
        else n1 = e.v0;    
    }
        
    while(true)
    {
        if(n0==n1)
        {
            return maxWeight;
        }
        
        Edge &e0 = tree[nodes[n0].parent];
        
        int curWeight = e0.weight;
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;    
        }        
        
        if(e0.v0 == n0) n0 = e0.v1;
        else n0 = e0.v0;

        Edge &e1 = tree[nodes[n1].parent];
        
        curWeight = e1.weight;
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;    
        }
                
        if(e1.v0 == n1) n1 = e1.v1;
        else n1 = e1.v0;
    }    
}*/


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

/*inline int parentNode(int nodeIndex)
{
    Edge &e = tree[nodes[nodeIndex].parent];
        
    if(e.v0 == n0) return e.v1;
    else return e.v0;    
}*/

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

void printDpWeight(const char *title)
{
    /*printf("-------- %s ---------\n",title);
    
    for(int i=0;i<=vCount;i++)
    {
        for(int j=0;j<=mylog2(tree.size());j++)
        {
            printf("%d   ",dpWeight[i][j]);    
        }
        printf("\n");
    }
    printf("---------------------\n");*/
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
        
                //printf("|%d, %d|\n", e.v0,e.v1);
                
                dp[i][0] = parentNode;
                dpWeight[i][0] = e.weight;
            }
            else
            {
                //printf("||%d||\n", i);
                dp[i][0] = i;
                dpWeight[i][0] = 0;
            }
        }
    }
    
    /*cout <<"323232"<<endl;
    cout <<minNode<<"   "<<maxNode<<endl;
    return;*/
    
    printDpWeight("set first col");
    
    int logValue = mylog2(treeSize);
        
    for(int j=1;j<=logValue;j++)        
    {
        //for(int i=0;i<treeSize;i++)
        //{
        for(int i=minNode;i<=maxNode;i++)
        {
            if(nodes[i].links.size()>0)
            {
                int weightPrev = dpWeight[i][j-1];
                int weightNext = dpWeight[ dp[i][j - 1] ]   [j - 1];
                            
                //printf("(%d, %d) ",weightPrev,weightNext);
                
                if(weightPrev > weightNext ) dpWeight[i][j] = weightPrev;
                else dpWeight[i][j] = weightNext;
                
                dp[i][j] = dp[ dp[i][j - 1] ]   [j - 1];    
            }
        }
        //printf("\n");
    }
}

int lcaFindMaxWeight(int v, int u)
{
    //printf("lcaFindMaxWeight %d, %d\n",v,u);
    
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
            //printf("depth %d   %d\n",nodes[u].depth, nodes[v].depth);
            if(nodes[u].depth - nodes[v].depth>=(1<<i))
            {
                if(dpWeight[u][i]>maxWeight)
                {
                    maxWeight = dpWeight[u][i];
                    //printf("max 1: %d\n",maxWeight);
                }
    
                //printf("u before %d   ",u);            
                u=dp[u][i];
                //printf("u after %d\n",u);
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
                //printf("max 2: %d\n",maxWeight);
            }
            if(dpWeight[v][i]>maxWeight)
            {
                maxWeight = dpWeight[v][i];   
                //printf("max 3: %d\n",maxWeight);
            }                        
            v = dp[v][i];
            u = dp[u][i];
            
            if(u==v)
            {
                return maxWeight;    
            }
        }
        /*else
        {
            printf("else %d %d\n",   dp[v][i] ,dp[u][i]);
        }*/
    }
        
    //printf("max 4: %d   %d\n",dpWeight[v][0],maxWeight);
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

//bool test=false;

int main()
{
    int eCount;
    
    initSet();
    
    scanf("%d %d",&vCount, &eCount);
    
    if(eCount<1)
    {
        return 0;    
    }    
    
    /*if(eCount==199997)
    {
        test=true;
    }*/
    
    
    
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
     
    
    /*if(test)
    {
        cout <<"31313131"<<endl;
        cout <<tree.size()<<endl;
        cout <<bigs.size()<<endl;
        return 0;
    }*/

        
    lcaPreprocess();

    /*cout <<"31313131"<<endl;
    
    return 0;*/

    
    printDpWeight("finish");
    

    for(auto &e : bigs)
    {
        //int maxWeight = findMaxWeight(e.v0,e.v1);
        int maxWeight = lcaFindMaxWeight(e.v0,e.v1);
        
        results[e.number] = treeResult - maxWeight + e.weight;
    }
    
        
    for(int i=1;i<=eCount;i++)
    {
        cout <<results[i]<<endl;    
    }
    
    return 0;    
}
