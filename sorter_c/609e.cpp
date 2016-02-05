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
    bool inTree=false;
};

struct Node{    
    int parent;
    int depth;    
    vector<int> links;
};

vector<Edge> tree;
//int visited[200001]={0};

Node nodes[200001];

int findMaxWeight(int n0, int n1)
{
    //printf("findMaxWeight %d, %d\n",n0,n1);
    
    int maxWeight = 0;
    
    int depthDif = nodes[n0].depth - nodes[n1].depth;
    
    //printf("^%d, %d^\n",nodes[n0].depth,nodes[n1].depth);
    
    for(int i=0;i<depthDif;i++)
    {
        //printf("[[%d]]\n",n0);
        
        
        int curWeight = tree[nodes[n0].parent].weight;
        
        //printf("[[cur weight %d]]\n",curWeight);
        
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;            
            //printf("[[max %d]]\n",maxWeight);
        }
        
        Edge &e = tree[nodes[n0].parent];
        if(e.v0 == n0) n0 = e.v1;
        else n0 = e.v0;
    }
    
    for(int i=0;i<-depthDif;i++)
    {
        //printf("{{%d]]\n",n1);
        
        int curWeight = tree[nodes[n1].parent].weight;
        
        //printf("[[cur weight %d]]\n",curWeight);
        
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;    
            //printf("{{max %d]]\n",maxWeight);
        }
        
        Edge &e = tree[nodes[n1].parent];
        if(e.v0 == n1) n1 = e.v1;
        else n1 = e.v0;    
    }
    
    int counter = 0;
    while(counter++<20)
    {
        //printf("<%d, %d>\n",n0,n1);
        
        if(n0==n1)
        {
            return maxWeight;
        }
        
        int curWeight = tree[nodes[n0].parent].weight;
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;    
        }
        //n0 = nodes[n0].parent;
        {
            Edge &e = tree[nodes[n0].parent];
            if(e.v0 == n0) n0 = e.v1;
            else n0 = e.v0;
        }
        
        curWeight = tree[nodes[n1].parent].weight;
        if(curWeight > maxWeight)
        {
            maxWeight = curWeight;    
        }
        //n1 = nodes[n1].parent;
        {
            Edge &e = tree[nodes[n1].parent];
            if(e.v0 == n1) n1 = e.v1;
            else n1 = e.v0;
        }
        
        //printf("<<%d, %d>>\n",n0,n1);
    }    
}


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

int counter2=0;

void walkTree(int cur, int parent,int depth)
{
    if(counter2++>20) return;
    //printf("walkTree %d, %d, %d\n",cur, parent, depth);
    
    Node &curNode = nodes[cur];
    
    curNode.depth = depth;
    curNode.parent = parent;
    
    for(int i=0;i<curNode.links.size();i++)
    {
        //printf("!");
        if(tree[curNode.links[i]].v0!=cur && curNode.links[i]!=parent)
        {
            //printf("a %d\n",cur);
            walkTree(tree[curNode.links[i]].v0, curNode.links[i], depth+1);
        }
        else if(tree[curNode.links[i]].v1!=cur && curNode.links[i]!=parent)
        {
            //printf("b %d\n",cur);
            walkTree(tree[curNode.links[i]].v1, curNode.links[i], depth+1);
        }
    }
}

int main()
{
    int vCount, eCount;
    vector<Edge> edges;
    
    initSet();
    
    scanf("%d %d",&vCount, &eCount);
    
    if(eCount<1)
    {
        return 0;    
    }
    
    edges.reserve(eCount);
    
    int minNode=2000000000;
    
    for(int i=0;i<eCount;i++)
    {
        Edge e;
        e.number = i+1;
        scanf("%d %d %d",&e.v0, &e.v1, &e.weight);
        if(e.v0>e.v1)
        {
            int temp = e.v1;
            e.v1 = e.v0;
            e.v0 = temp;
        }
        if(e.v0<minNode)
        {
            minNode = e.v0;    
        }                   
        edges.push_back(e);
    }
    
    sort(edges.begin(), edges.end(), [](const Edge &e0, const Edge &e1)
        {
            return e0.weight > e1.weight;    
        });
    
    //printf("----------\n");
    /*for(auto &e : edges)
    {
        //printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);    
    } */   
    
    //map<int,int> vCounters;    
    
    
    //int i = eCount-1;
    
    /*for(auto& e : edges)
    {
        printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);                
    }
    
    printf("======================\n");*/
    
    for(int i=eCount-1;i>=0;--i)
    {
        Edge &e = edges[i];
        
        int foundNumber0 = find(e.v0);
        int foundNumber1 = find(e.v1);
        
        //printf("[!%d,%d   %d,%d!]\n",e.v0,e.v1,foundNumber0,foundNumber1);
        
        if(foundNumber0!=foundNumber1)
        {
            unite(e.v0, e.v1);
                        
            tree.push_back(e);            
            
            //printf("|%d,%d|\n",e.v0,e.v1);
            nodes[e.v0].links.push_back(tree.size()-1);
            nodes[e.v1].links.push_back(tree.size()-1);
            e.inTree = true;
            edges.erase(edges.begin()+i);
        }
        else
        {
            //printf("!%d,%d!\n",e.v0,e.v1);
        }
    }        
    
    long long int treeResult = 0;
    
    /*sort(tree.begin(), tree.end(), [](const Edge &e0, const Edge &e1)
        {
            return e0.v0 < e1.v0;    
        });*/    
    
    for(auto& e : tree)
    {        
        //printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);        
        treeResult += e.weight;
    }

    for(auto& e : tree)
    {       
        e.result = treeResult;
    }

    /*
    for(int i=0;i<200001;i++)
    {
        if(nodes[i].links.size()>0)
        {
            printf("node %d: ",i);
            for(auto& l : nodes[i].links)
            {
                if(tree[l].v0!=i)
                {
                    printf("%d ",tree[l].v0);
                }
                else
                {
                    printf("%d ",tree[l].v1);
                }
            }
            printf("\n");
        }
    }*/
    
    
    walkTree(minNode, -1, 0);
    
/*
    printf("--------------\n");    
    for(int i=0;i<200001;i++)
    {
        if(nodes[i].links.size()>0)
        {
            printf("node %d   depth: %d: ",i,nodes[i].depth);
            for(auto& l : nodes[i].links)
            {
                if(tree[l].v0!=i)
                {
                    printf("(%d   weight: %d)",tree[l].v0, tree[l].weight);
                }
                else
                {
                    printf("(%d   weight: %d)",tree[l].v1, tree[l].weight);
                }
            }
            printf("\n");
        }
    }
    
    for(auto &e : edges)
    {
        printf("* %d, %d *   %d\n",e.v0,e.v1,e.weight);
    }      */ 
    
    
    //printf("----------\n");
    for(auto &e : edges)
    {
        //if(e.inTree=false)
        {
            //printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);    
            int maxWeight = findMaxWeight(e.v0,e.v1);
            
            
            //printf("max %d   %d   %d\n",e.v0,e.v1, maxWeight);
            e.result = treeResult - maxWeight + e.weight;
        }
    }
    
    copy(tree.begin(), tree.end(), back_inserter(edges));
    
    sort(edges.begin(), edges.end(), [](const Edge &e0, const Edge &e1)
        {
            return e0.number < e1.number;    
        });      

    for(auto &e : edges)
    {
        //if(!e.inTree)
        {
        cout <<e.result<<endl;
        }
    }        
    
    return 0;    
}

