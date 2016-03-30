#include <bits/stdc++.h>

using namespace std;

void debug(const char *format, ...)
{
    /*va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);



template<class TMap,class TKey,class TValue>
inline bool tryGetValue(TMap &m, TKey &key, TValue &u)
{
    auto it = m.find(key);
    if(it!=m.end())
    {
        u = it->second;
        return true;
    }
    return false;
}



std::ios::sync_with_stdio(false);
cin.tie(0);

//set elements to needed value
int directory[100];
std::fill(directory, directory + 100, -1);

//print int64
printf("%I64d ",q.back()+x);


#define forn(i, n) for (int i = 0; i < (int)(n); ++i)



usersEmplace.emplace(key, "abc");
usersIndex[key] = User("abc");
usersInsert.insert(pair<string,User>(key, User("abc")));


nextSet->insert(r);
nextSet->erase(r);  
nextSet->count(r);



/*
Про stdc++.h

В программе пишешь один #include <bits/stdc++.h>
Вызываешь (надо папку с stdc++ найти):
g++ -Winvalid-pch -x c++-header -g -O2 -o ./stdc++.h.gch /usr/include/i386-linux-gnu/c++/4.9/bits/stdc++.h

Потом билдишь:
g++ -I. -include stdc++.h -H -g -O2 ./$PROGRAM.cpp -o ./$PROGRAM

Начинает все супер быстро билдиться!

Описание:
https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_headers.html
*/	
	
===========================================================================================================

#define debug(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}




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



//========= поиск максимальной возрастающей подпоследовательности (элементы отличаются только на +1) =========
    map<int,int> m;
    int mx = 1;
    
    for (int i=0; i<n; i++) 
    {
        int v;
        if(tryGetValue(m,a[i]-1,v))
        {
            m[a[i]] = v+1;
            if(v+1>mx) mx=v+1;
        }
        else
        {
            m[a[i]] = 1;
        }
    }      
//========= поиск максимальной возрастающей подпоследовательности (элементы отличаются только на +1) =========



