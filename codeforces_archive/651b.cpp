#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

int bs[1000] = {0};
int ts[1001] = {0};

int main()
{
    int n;

    scanf("%d", &n);

    int maxBs = 0;

    for (int i = 0; i < n; ++i)
    {
        int b;
        scanf("%d", &b);
        --b;
        ++bs[b];
        if (bs[b] > maxBs)
        {
            maxBs = bs[b];
        }
        ++ts[bs[b]];
    }

    int result = 0;

    for (int i = 1;i <= maxBs;i++)
    {
        result += ts[i] - 1;
    }

    printf("%d\n", result);

    return 0;
}

