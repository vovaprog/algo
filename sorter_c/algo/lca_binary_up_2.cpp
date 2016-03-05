//609e
//http://neerc.ifmo.ru/wiki/index.php?title=%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B4%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%BE%D0%B3%D0%BE_%D0%BF%D0%BE%D0%B4%D1%8A%D0%B5%D0%BC%D0%B0
//Метод двоичного подъема из задачи 609e.

#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;


struct Edge{
    int v0,v1;
//    int weight;
//    int number;
};

struct Node{    
    int parent;
    int depth;    
    vector<int> links;
};

vector<Edge> tree;
int minNode=2000000000;
int maxNode=0;
Node nodes[200001];

int dp[200001][19]={0};
//int dpWeight[200001][19]={0};


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
            }
            else
            {
                dp[i][0] = i;
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
                dp[i][j] = dp[ dp[i][j - 1] ]   [j - 1];    
            }
        }
    }
}

int lcaFind(int v, int u)
{
    if(nodes[v].depth > nodes[u].depth)
    {
    	swap(v,u);
    }

    int logValue = mylog2(tree.size()); 
    
    if(nodes[u].depth!=nodes[v].depth)
    {
        for(int i = logValue;i>=0;i--)
        {
            if(nodes[u].depth - nodes[v].depth>=(1<<i))
            {                 	
                u=dp[u][i];
            }
        }
    }
    
    if(u==v) 
    {
    	return u;
    }
    
    int i;
    for(i = logValue;i>=0;--i)
    {
        if(dp[v][i]!=dp[u][i])
        {                             
            v = dp[v][i];
            u = dp[u][i];
            
            if(u==v)
            {
                return u;    
            }
        }
    }
        
    return dp[v][0];   
}

const char *testText="8\n"
"1 2\n"
"2 3\n"
"3 4\n"
"3 5\n"
"2 6\n"
"6 7\n"
"6 8\n"
"8 9\n";

int main()
{
    int eCount;
    
    stringstream ss;
    
    ss << testText;
    
    ss >>eCount;
    
    if(eCount<1)
    {
        return 0;    
    }    
    
    tree.reserve(eCount);
    
    for(int i=0;i<eCount;i++)
    {
        Edge e;
        ss >> e.v0 >> e.v1;

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
        
        tree.push_back(e);
        nodes[e.v0].links.push_back(tree.size()-1);
        nodes[e.v1].links.push_back(tree.size()-1);
    }
    
    walkTree(minNode, -1, 0);
    
    lcaPreprocess();
    
    int anc;
    
    anc = lcaFind(4,8);    
    printf("result: %d     answer: 2\n",anc);
    
    anc = lcaFind(5,9);    
    printf("result: %d     answer: 2\n",anc);
    
    anc = lcaFind(5,1);    
    printf("result: %d     answer: 1\n",anc);
    
    anc = lcaFind(5,4);    
    printf("result: %d     answer: 3\n",anc);

    anc = lcaFind(7,6);    
    printf("result: %d     answer: 6\n",anc);    
    
    return 0;
}

