#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

template <class TMap, class TKey, class TValue>
inline bool tryGetValue(TMap &m, TKey &key, TValue &u)
{
    auto it = m.find(key);
    if (it != m.end())
    {
        u = it->second;
        return true;
    }
    return false;
}

struct Pair
{
    int start, end, index, minDist;
    
    Pair(int start, int end, int index): start(start), end(end), index(index), minDist(2000000000)
    {}    
    Pair(): minDist(2000000000)
    {}
};

int comparePairs( const void* al0, const void* al1)
{
    return ((Pair*)al0)->start - ((Pair*)al1)->start;    
}

int buf[500000];

#define INF 2000000000
/*vector<int> t;
int n;

void init (int nn)
{
	n = nn;
	//t.assign (n, INF);
	t.reserve(n);
	for(int i=0;i<n;i++) 
	{
		//t[i] = INF;
		t.push_back(INF);
	}
}

int getmin (int r)
{
	int result = INF;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result = min (result, t[r]);
	return result;
}

void update (int i, int new_val)
{
	debug("update %d, %d",i,new_val);
	for (; i < n; i = (i | (i+1)))
	{
		t[i] = min (t[i], new_val);
		//debug("%d",t[i]);
	}
}*/

/*void init (vector<int> a)
{
	init ((int) a.size());
	for (unsigned i = 0; i < a.size(); i++)
		update (i, a[i]);
}*/


/*int n, t[4*500000];

void build (int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
		//t[v] = t[v*2] + t[v*2+1];
		t[v] = min(t[v*2], t[v*2+1]);
	}
}

int sumT (int v, int tl, int tr, int l, int r) {
    debug("sumT %d, %d, %d, %d, %d",v,tl,tr,l,r);
    
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	
	int sum0 = sumT (v*2, tl, tm, l, min(r,tm));
	int sum1 = sumT (v*2+1, tm+1, tr, max(l,tm+1), r);
	
	debug("%d   %d",sum0,sum1);
	
	return min( sumT (v*2, tl, tm, l, min(r,tm)),
		 sumT (v*2+1, tm+1, tr, max(l,tm+1), r));		
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[v*2] + t[v*2+1];
	}
}*/

int tree_data[4 * 500000];  
int TREE_REAL_DATA;
 
// основная функция поиска.
// аргументы: p - текушая вершина(пронумерованы согласно рисунку).
// l, p - левая и правая границы отрезка, для которого tree_data[p] является максимумом.
// вообще можно было обойтись без этих параметров, и определять их исходя из p, но так проще и понятней.
// a, b - левая и правая границы отрезка, для которого необходимо найти минимум.
int __tree_find_max(int p, int l, int r, int a, int b) 
{
    debug("__tree_find_max %d, %d, %d, %d, %d", p,l,r,a,b);
if (b < l || r < a) return INF;
if (a <= l && r <= b) return tree_data[p];
int r1 = __tree_find_max(p*2  , l, (l+r) / 2,   a, b); // опрос левого предка
int r2 = __tree_find_max(p*2+1, (l+r)/2 + 1, r, a, b); // опрос правого предка
return min(r1, r2); // нахождение большего из левого и правого поддеревьев
}
 
// более юзабильная оболочка для функции выше.
int tree_find_max(int a, int b)
{
return __tree_find_max(1, 0, TREE_REAL_DATA - 1, a, b);
}
 
// обновление элемента № р.
void tree_update(int p, int x) 
{
p += TREE_REAL_DATA; // преобразование позиции p к позиции в самом нижнем массве,
// в котором реально находится массив со значениями.
tree_data[p] = x;
for(p/=2; p ; p/=2) {
if (tree_data[p * 2] < tree_data[p * 2 + 1])
tree_data[p] = tree_data[p * 2];
else tree_data[p] = tree_data[p * 2 + 1];
}
} 
 
// простейшая инициализация - установка всех значений в -INF
void tree_init()
{
for (int i = 0; i < TREE_REAL_DATA * 2; i++) 
tree_data[i] = INF;
}


int sz;

/*void build_tree()
{
    
	// размер, доведённый до степени двойки
	int n = (1 << ((int)log(sz - 1) + 1));
	//V.resize(2 * n, INF);	
	debug("^^%d",n);
	// инициализируем листы
	for (int i = n; i < 2 * n; i++)
		t[i] = buf[i - n];

	// и все остальные вершины
	for (int i = n - 1; i > 0; i--)
		t[i] = min(t[2 * i], t[2 * i + 1]);
}

int rmq_up(int l, int r)
{
	int ans = INF;
	int n = sz;
	l += n - 1, r += n - 1;
	while (l <= r)
	{
		// если l - правый сын своего родителя, 
		// учитываем его фундаментальный отрезок
		if (l & 1)
			ans = min(ans, t[l]);
		// если r - левый сын своего родителя, 
		// учитываем его фундаментальный отрезок
		if (!(r & 1))
			ans = min(ans, t[r]);
		// сдвигаем указатели на уровень выше
		l = (l + 1) / 2, r = (r - 1) / 2;
	}		
	return ans;
}*/




void printT()
{
	printf("[[[   ");
	//for(int i : t)
	for(int i=0;i<sz*2;i++)
	{
//	    if(t[i]==INF) printf("INF ");
//	    else printf("%d ",t[i]);
	
	    if(tree_data[i]==INF) printf("INF ");
	    else printf("%d ",tree_data[i]);
	}
	printf("]]]\n");
}

int main()
{
    int nRequests;

    scanf("%d %d", &sz, &nRequests);

    unordered_map<int, int> m;
    vector<Pair> rqs;
    rqs.reserve(nRequests);
    
    int val;
    
    //init(sz);
    TREE_REAL_DATA = sz;
    tree_init();
    
    for (int i = 0;i < sz;i++)
    {
    	int b;
    	
        scanf("%d", &b);
        
        if (tryGetValue(m, b, val))
        {
            //buf[i] = i - val;
            buf[val] = i-val;
            tree_update(val,i-val);
        }        
        //else
        {
            buf[i] = INF;
        }
        m[b] = i;   
        //update(i,buf[i]);
        
        //debug("buf[%d]=%d",i , buf[i]);
        
        tree_update(i,INF);
    }

    //build_tree();
    
    //build(buf,1,0,sz-1);
    printT();
    
//    printT();
    
    for(int q=0;q<nRequests;q++)
    {
        int rqStart,rqEnd;
        
        scanf("%d %d",&rqStart, &rqEnd);
        --rqStart;
        --rqEnd;    
        
        rqs.emplace_back(rqStart,rqEnd,q);
    }
    printf("------------------------\n");
    /*sort(rqs.begin(),rqs.end(),[](const Pair &p0,const Pair &p1)
    	{
    		//return p0.end < p1.end;
    		return p0.start < p1.start;
    	});*/
    	
    qsort(rqs.data(),nRequests,sizeof(Pair),comparePairs);
    	
    int lastClear = 0;
    
    for(auto &rq : rqs)
    {
        debug("rq start=%d end=%d",rq.start,rq.end);
        
    	for(int i=lastClear;i<rq.start;i++)
    	{    		
    	    debug("loop %d %d",i,buf[i]);
    		if(buf[i]!=INF) 
    		{
    			//update(i,INF);
    			//t[i] = INF;
    			//update(1,0,sz-1,i,INF);
    			tree_update(i,INF);
    			debug("update %d",i);
    			//printT();
    		}
    	}
    	lastClear = rq.start;
    	
    	//rq.minDist = getmin(rq.end);
    	printf("------------------------\n");
    	//rq.minDist = sumT(1,0,sz-1,rq.start,rq.end);
    	//rmq_up(rq.start,rq.end);
    	rq.minDist = tree_find_max(rq.start,rq.end);
    	int v = tree_find_max(rq.start,rq.end);
    	if(v
    	
    	debug("%d",rq.minDist);
    }
    
    
    for(auto &rq : rqs)
    {
    	buf[rq.index] = rq.minDist == 2000000000?-1:rq.minDist;	
    }
    
    for(int i=0;i<nRequests;i++)
    {
    	printf("%d\n",buf[i]);	
    }

    return 0;
}