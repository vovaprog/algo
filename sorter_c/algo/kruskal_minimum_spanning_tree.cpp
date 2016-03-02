//609e

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


int p[200001], rankCount[200001];

vector<Edge> tree;

Node nodes[200001];
Edge edges[200001];


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

int compareEdge( const void* al0, const void* al1)
{
    return ((Edge*)al1)->weight - ((Edge*)al0)->weight;    
}


{
    qsort( edges, eCount, sizeof(Edge), compareEdge );
    
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
    } 
}

