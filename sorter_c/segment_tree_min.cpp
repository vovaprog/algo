
//================================================================
//===================== segment tree (min) =======================
//================================================================

#define INF 2000000000

int *t;
int treeSize;

void segmentTreeInit(int size)
{
    treeSize = size;
    
    int tSize = size * 4;
    
    t = new int[tSize];
    
    for(int i=0;i<tSize;i++)
    {
        t[i] = INF;
    }
}

int _segmentTreeFind(int v, int tl, int tr, int l, int r) 
{
	if (l > r)
	{
		return INF;
	}
	if (l == tl && r == tr)
	{
		return t[v];
	}
	
	int tm = (tl + tr) / 2;
	
	return min(
	    _segmentTreeFind (v*2, tl, tm, l, min(r,tm)),
		_segmentTreeFind (v*2+1, tm+1, tr, max(l,tm+1), r)
		);
}

int segmentTreeFind(int l, int r)
{
    return _segmentTreeFind(1,0,treeSize-1,l,r);
}

void _segmentTreeUpdate(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
	{
		t[v] = new_val;
	}
	else 
	{
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			_segmentTreeUpdate (v*2, tl, tm, pos, new_val);
		else
			_segmentTreeUpdate (v*2+1, tm+1, tr, pos, new_val);
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

void segmentTreeUpdate(int pos, int newVal)
{
    _segmentTreeUpdate(1,0,treeSize-1,pos,newVal);
}

void segmentTreePrint()
{
	printf("[[[   ");
	for(int i=0;i<treeSize * 4;i++)
	{	
	    if(t[i]==INF) printf("INF ");
	    else printf("%d ",t[i]);
	}
	printf("]]]\n");
}

//================================================================
//===================== segment tree (min) =======================
//================================================================

