#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);
#define debug3(arg) cout << #arg << " = " << arg << "\n";

typedef long long int int64;

char s[100010];

set<int> vals;
int neededLetters = 0; 

int main()
{
    int n;

    scanf("%d",&n);
    scanf("%s",s);

    for(int i = 0; i < n; ++i)
    {
        int x = (int)s[i];
        
        if(vals.count(x)==0)
        {
            vals.insert(x);
        }
        else
        {
            ++neededLetters;
            if(neededLetters + vals.size()>26)
            {
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%d\n",neededLetters);

    return 0;
}
