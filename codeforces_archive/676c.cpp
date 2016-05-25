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

int k;
char s[100100]={0};
int len=0;


void getRange(char ch, int &outStart, int &outEnd)
{
    int i;
    
    for(i=outStart;i<len;++i)
    {
        if(s[i]==ch) break;
    }
    
    outStart = i;
    
    int curK = k;
    
    for(;i<len;++i)
    {
        if(s[i]!=ch) --curK;
        if(curK<0) break;
    }
    
    outEnd = i;    
}

void moveRange(char ch, int &outStart, int &outEnd)
{
    int i;
    
    for(i=outStart; i<len; ++i)
    {
        if(s[i]!=ch) break;        
    }    
    for(;i<len;++i)
    {
        if(s[i]==ch) break;    
    }
    
    outStart = i;
    
    if(outStart>=len)
    {
        outEnd = outStart;
        return;
    }
            
    getRange(ch, outStart,outEnd);
}

int getLen(int start, int end)
{
    int result = end - start;

    return result;
}

int getResult(char ch)
{
    int start = 0, end;
    getRange(ch, start, end);
    
    int maxLen = getLen(start,end);
    
    while(end < len)
    {
        moveRange(ch, start, end);
                
        maxLen = max(maxLen, getLen(start,end));
    }
    
    return maxLen;
}

int main()
{
    int n;

    scanf("%d %d",&n,&k);

    scanf("%s",s);
    
    len = n;
    
    int resA = getResult('a');
    
    int resB = getResult('b');
    
    int result = max(resA, resB);
    
    printf("%d\n", result);
    
    return 0;
}
