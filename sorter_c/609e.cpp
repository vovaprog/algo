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

vector<Edge> tree;
int visited[100000]={0};

int findMaxWeight(int start, int end, int maxWeight,int maxWeightResult)
{    
    for(int i=0;i<tree.size();i++)
    {
        if(!visited[tree[i].number])
        {
            if(tree[i].v0 == start)
            {
                //printf(">v0> %d   %d   %d   (%d,%d)\n",start,end,maxWeight,tree[i].v0,tree[i].v1);
                if(tree[i].weight > maxWeight)
                {
                    maxWeight = tree[i].weight;    
                }
                if(tree[i].v1==end)
                {
                    return maxWeight;    
                }
                if(tree[i].v1!=end && visited[tree[i].number]==0)
                {
                    visited[tree[i].number] = 1;
                    int callResult = findMaxWeight(tree[i].v1,end,maxWeight,maxWeightResult);
                    if(callResult>maxWeight) maxWeight = callResult;
                    if(callResult!=0) maxWeightResult = callResult;
                    visited[tree[i].number] = 0;
                }
            }
            if(tree[i].v1 == start)
            {
                //printf(">v0> %d   %d   %d   (%d,%d)\n",start,end,maxWeight,tree[i].v0,tree[i].v1);
                if(tree[i].weight > maxWeight)
                {
                    maxWeight = tree[i].weight;    
                }
                if(tree[i].v0==end)
                {
                    return maxWeight;    
                }
                if(tree[i].v0!=end && visited[tree[i].number]==0)
                {
                    visited[tree[i].number] = 1;
                    int callResult = findMaxWeight(tree[i].v0,end,maxWeight,maxWeightResult);
                    if(callResult>maxWeight) maxWeight = callResult;
                    if(callResult!=0) maxWeightResult = callResult;
                    visited[tree[i].number] = 0;
                }
            }   
        }
    }
    
    return maxWeightResult;
}

int main()
{
    int vCount, eCount;
    vector<Edge> edges;
    
    scanf("%d %d",&vCount, &eCount);
    
    edges.reserve(eCount);
    
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
        edges.push_back(e);
    }
    
    sort(edges.begin(), edges.end(), [](const Edge &e0, const Edge &e1)
        {
            return e0.weight > e1.weight;    
        });
    
    /*printf("----------\n");
    for(auto &e : edges)
    {
        printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);    
    } */   
    
    map<int,int> vCounters;    
    
    
    //int i = eCount-1;
    
    /*for(auto& e : edges)
    {
        printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);                
    }
    
    printf("======================\n");*/
    
    for(int i=eCount-1;i>=0;--i)
    {
        Edge& e = edges[i];
        
        int v0Counter = vCounters[e.v0];
        int v1Counter = vCounters[e.v1];
        
        //printf("(%d,%d   %d,%d)\n",e.v0,e.v1,v0Counter,v1Counter);  
        
        if(v0Counter<1 || v1Counter<1)
        {
            tree.push_back(e);
            edges.erase(edges.begin()+i);
            
            vCounters[e.v0]++;
            vCounters[e.v1]++;
        }                
    }        

    long long int treeResult = 0;
    
    /*sort(tree.begin(), tree.end(), [](const Edge &e0, const Edge &e1)
        {
            return e0.v0 < e1.v0;    
        });*/    
    
    for(auto& e : tree)
    {        
        printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);        
        treeResult += e.weight;
    }

    for(auto& e : tree)
    {       
        e.result = treeResult;
    }
    
    //printf("----------\n");
    for(auto &e : edges)
    {
        //printf("[%d,%d   %d]\n",e.v0,e.v1,e.weight);    
        int maxWeight = findMaxWeight(e.v0,e.v1,0,0);
        //printf("max %d   %d   %d\n",e.v0,e.v1, maxWeight);
        e.result = treeResult - maxWeight + e.weight;
    }
    
    copy(tree.begin(), tree.end(), back_inserter(edges));
    
    sort(edges.begin(), edges.end(), [](const Edge &e0, const Edge &e1)
        {
            return e0.number < e1.number;    
        });      

    for(auto &e : edges)
    {
        cout <<e.result<<endl;
    }        
    
    return 0;    
}

