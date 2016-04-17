#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;


int main()
{
    int nTests;
    
    cin >> nTests;

    for(int tst=0;tst<nTests;++tst)
    {
        int64 l,r;
        cin >>l>>r;

        int64 result=0;

        for(int64 d=1;d<=r;d+=2)
        {
            int64 col = (r / d) - (l / d);
            if(l % d==0) ++col;
            result += col * d;
        }

        cout <<result << endl;
    }
    
    
    return 0;
}
