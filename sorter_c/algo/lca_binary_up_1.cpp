//609e
//http://neerc.ifmo.ru/wiki/index.php?title=%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B4%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%BE%D0%B3%D0%BE_%D0%BF%D0%BE%D0%B4%D1%8A%D0%B5%D0%BC%D0%B0
//Метод двоичного подъема из задачи 609e.

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