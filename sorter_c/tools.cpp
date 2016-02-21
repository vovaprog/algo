#include <bits/stdc++.h>

using namespace std;

void debug(const char *format, ...)
{
    /*va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);*/            
}


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
	