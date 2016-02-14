#include <stdio.h>
#include <vector>
#include <stdarg.h>
#include <deque>

using namespace std;

vector<int> rails[4000];
vector<int> roads[4000];

#define ROAD_WEIGHT 1

void debug(const char *format, ...)
{
/*    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}

int pathWeights[4000];
int trace[4000];
bool visited[4000];

bool dijkstra(vector<int> *vs, int nVs, int start, int end, deque<int> &path, deque<int> &avoidPath)
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
            if(!visited[i] && pathWeights[i]>=0 && pathWeights[i]<minWeight &&
                (avoidPath.size()<=pathWeights[i] || avoidPath[pathWeights[i]]!=i))
            {
                minWeight = pathWeights[i];
                curRoot = i;
            }
        }
                
        //======================================                
        
        if(curRoot < 0)
        {
            return false;    
        }

        if(curRoot == end)
        {
            path.clear();
            path.push_back(end);
            while(curRoot!=start)
            {
                curRoot = trace[curRoot];
                if(curRoot==start) break;
                path.push_front(curRoot);
            }                        
            return true;    
        }
        
        //======================================        
       
        visited[curRoot] = true;
        
        for(int i=0;i<vs[curRoot].size();i++)
        {
            int w = pathWeights[curRoot] + ROAD_WEIGHT;
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
        rails[t1].push_back(t0);
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
            }
        }        
    }
    
    deque<int> railPath;
    deque<int> roadPath;
    int result = 100500;
    
    if(dijkstra(rails, nTowns, 0, nTowns-1, railPath, roadPath))
    {        
        if(dijkstra(roads, nTowns, 0, nTowns-1, roadPath, railPath))
        {    
            if(railPath.size()<roadPath.size())
            {
                result = roadPath.size();    
            }
            else
            {
                result = railPath.size();    
            }
        }
    }
    
    railPath.clear();
    if(dijkstra(roads, nTowns, 0, nTowns-1, roadPath, railPath))
    {        
        if(dijkstra(rails, nTowns, 0, nTowns-1, railPath, roadPath))
        {    
            if(railPath.size()<roadPath.size())
            {
                if(roadPath.size()<result)
                {
                    result = roadPath.size();
                }
            }
            else
            {
                if(railPath.size()<result)
                {
                    result = railPath.size();
                }
            }
        }
    }
    
    if(result==100500)
    {
        result = -1;    
    }
    
    printf("%d",result);
    
    return 0;    
}

