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

