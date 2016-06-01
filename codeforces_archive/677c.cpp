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

int countZeros(int v)
{
    debug2("enter %d",v);
    
    int zeros = 0;
    for(int i=0;i<6;++i)
    {
         if(( v & (1<<i) ) ==0)
         {
            ++zeros;    
         }         
    }
    
    debug2("%d",zeros);
    
    return zeros;
}

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);

    scanf("%s",s);

    int n = strlen(s);
    
    int result = 0;
    
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
        
        result += zeroCount;
    }

    debug2("result = %d",result);
    
    result = (1 << result);
    
    result = result % (1000000000 + 7);
    
    printf("%d\n", result);
    
    return 0;
}
