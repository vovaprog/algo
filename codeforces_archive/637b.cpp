#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int main()
{
    int n;
    
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    vector<string> input;
    input.reserve(n);
    
    for(int i = 0; i < n; ++i)
    {
        char s[15];
        cin >> s;
        input.emplace_back(s);
    }
    
    unordered_set<string> output;
    
    for(int i=n-1;i>=0;--i)
    {
        if(output.count(input[i])==0)
        {
            cout <<input[i]<<"\n";
            output.insert(input[i]);
        }        
    }
    
    return 0;
}
