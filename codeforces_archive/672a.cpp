#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);
#define debug3(arg) //cout << #arg << " = " << arg << "\n";

typedef long long int int64;

void getResult(int x, int pos)
{
    string s = to_string(x);
    
    char dig = s[pos];
    cout <<dig<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    
    --n;

    int x = 0, pos = -1, inc = 1;
    
    while(true)
    {
        if(pos >= n)
        { 
            getResult(x, n - (pos + 1 - inc));
            return 0;
        }
        
        ++x;
                
        if(x==10) inc=2;
        else if(x==100) inc=3;
        else if(x==1000) inc=4;
        else if(x==10000) inc=5;
        else if(x==100000) inc=6;
        else if(x==1000000) inc=7;
        
        pos += inc;
    }
    
    for(int i = 0; i < n; ++i)
    {
        int r;
        cin >> r;
    }


    return 0;
}
