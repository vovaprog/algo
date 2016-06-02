#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

//=====================================================================
#define debug3(args...) { vector<string> v = splitArgNames(#args); debugPrint(v.begin(), args); }
vector<string> splitArgNames(const string& s) 
{ vector<string> v; stringstream ss(s); for (string x; getline(ss, x, ',');) { v.emplace_back(x); } return move(v); }
void debugPrint(vector<string>::iterator it) { cout <<"\n"; }
template<typename T, typename... Args>
void debugPrint(vector<string>::iterator it, T head, Args... args) 
{ cout << *it <<" = "<< head << "     "; debugPrint(++it, args...); }
//=====================================================================

typedef long long int int64;

char s[100100];

const int64 MODUL = 1000000000 + 7;

int countZeros(int v)
{
    int zeros = 0;
    for(int i=0;i<6;++i)
    {
         if(( v & (1<<i) ) ==0)
         {
            ++zeros;    
         }         
    }
    
    return zeros;
}

inline int64 mul_modul(int64 x, int64 y, int64 modul)
{
    return ((x % modul) * (y % modul)) % modul;
}

inline int64 power_modul(int64 base, int64 pwr, int64 modul)
{
    int64 result = 1;
    
    for(int i=1; i<=pwr; ++i)
    {
        result = mul_modul(result, base, modul);
    }
    
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin.getline(s, 100100);    

    int n = strlen(s);
    
    int totalZeros = 0;
    
    for(int i = 0; i < n; ++i)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i] = s[i] - (int)'A'+ 10;    
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            s[i] = s[i] - (int)'a' + 36;    
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            s[i] = s[i] - (int)'0';     
        }        
        else if(s[i]=='-')
        {
            s[i] = 62;    
        }
        else if(s[i]=='_')
        {
            s[i] = 63;    
        }
        
        int zeroCount = countZeros(s[i]);
        
        totalZeros += zeroCount;
    }
    
    int64 result = power_modul(3, totalZeros, MODUL);
    
    cout <<result<<endl;
    
    return 0;
}

