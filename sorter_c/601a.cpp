#include <stdio.h>
#include <vector>

using namespace std;

vector<int> rails[4000];
vector<int> roads[4000];
vector<int> weights[4000];

int pathWeights[4000];
int trace[4000];
bool visited[4000];

bool dejkstra(vector<int> *vs, vector<int> *weights, int nVs, int start, int end, vector<int> &path)
{
    for(int i=0;i<nVs;i++)
    {
        pathWeights[i] = -1;
        visited[i] = false;
    }
    pathWeights[start] = 0;

    while(true)        
    {
        int minWeight = 2000000000;
        int curRoot = -1;
        
        for(int i=0;i<nVs;i++)
        {
            if(!visited[i] && pathWeights[i]>=0 && pathWeights[i]<minWeight)
            {
                minWeight = pathWeights[i];
                curRoot = i;
            }
        }
        
        //======================================        
        
        printf("curRoot: %d\n",curRoot);
        
        if(curRoot < 0)
        {
            return false;    
        }

        if(curRoot == end)
        {
            path.push_back(end);
            while(curRoot!=start)
            {
                curRoot = trace[curRoot];
                path.push_back(curRoot);                
            }                        
            return true;    
        }
        
        //======================================        
       
        visited[curRoot] = true;
        
        for(int i=0;i<vs[curRoot].size();i++)
        {
            int w = pathWeights[curRoot] + weights[curRoot][i];
            if(pathWeights[vs[curRoot][i]]<0 || pathWeights[vs[curRoot][i]]>w)
            {
                pathWeights[vs[curRoot][i]] = w;
                trace[vs[curRoot][i]] = curRoot;
            }            
        }        
    }        
}

int main()
{
    int nTowns, nRails;
    
    scanf("%d %d",&nTowns, &nRails);
    
    for(int i=0;i<nRails;i++)
    {
        int t0, t1;
        scanf("%d %d",&t0,&t1);
        --t0;--t1;
        rails[t0].push_back(t1);
        weights[t0].push_back(1);
        rails[t1].push_back(t0);
        weights[t1].push_back(1);
    }
    
    for(int i=0;i<nTowns;i++)
    {
        for(int j=i+1;j<nTowns;j++)
        {
            int q;
            for(q = 0;q<rails[i].size() && rails[i][q]!=j;q++);
            if(q==rails[i].size())
            {
                roads[i].push_back(j);
                roads[j].push_back(i);
                weights[i].push_back(1);
                printf("[%d, %d]\n",i,j);
            }
        }        
    }
    
    //while(true)
    {
        vector<int> railPath;
        vector<int> roadPath;
        
        dejkstra(rails, weights, nTowns, 0, nTowns-1, railPath);
        printf("++++++++++++++++++\n\n");
        
        dejkstra(roads, weights, nTowns, 0, nTowns-1, roadPath);
        
        for(auto &r : railPath)
        {
            printf("%d   ",r);    
        }

        printf("\n=======\n");
        
        for(auto &r : roadPath)
        {
            printf("%d   ",r);    
        }
        printf("\n");
        
        if(railPath.size()<roadPath.size())
        {
            printf("%d\n",roadPath.size()-1);    
        }
        else
        {
            printf("%d\n",railPath.size()-1);
        }            
    }
    
    return 0;    
}

