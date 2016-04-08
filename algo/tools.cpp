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

printf("%I64d ",x);

int64 k;
scanf("%I64d",&k);

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



//================================== multimap ===================================================
multimap<string,string> mm;

//insert
mm.insert(make_pair("key1","val11"));
mm.emplace("key1","val12");

//iterate
for(auto &p : mm)
{
	cout <<p.first<<" "<<p.second<<endl;	    	
}
cout <<mm.begin()->first<<endl;   


//get elements by key (p is pair - first, second)
auto p = mm.equal_range(key); 
    
for(auto it=p.first;it!=p.second;++it)
{
	cout <<it->second<<endl;	
}

//get number of found items:
cout <<"number of items: "<<distance(p.first,p.second)<<endl;

//erase
int removedCount = mm.erase(key); //Return value Number of elements removed.
auto p2 = mm.equal_range(key);
mm.erase(p2.first,p2.second); //Return value  Iterator following the last removed element.
auto p2 = mm.equal_range(key);
mm.erase(p2.first); //Return value  Iterator following the last removed element.

//number of elements with specific key:
mm.count(key);

//number of elements
mm.size();

//================================== multimap ===================================================



    //=================== priority queue ==========================    
    priority_queue<string> q;
    q.push("hello");
    q.emplace("world");
    q.push("program");
    cout <<q.top()<<" "<<q.top()<<q.size()<<endl;
    q.pop();
    cout <<q.top()<<" "<<q.top()<<q.size()<<endl;    
    //=================== priority queue ==========================

