#include <bits/stdc++.h>

using namespace std;

void debug(const char *format, ...)
{
    /*va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}

#define debug(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);


nextSet->insert(r);
nextSet->erase(r);  
nextSet->count(r);


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


usersEmplace.emplace(key, "abc");
usersIndex[key] = User("abc");
usersInsert.insert(pair<string,User>(key, User("abc")));


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


