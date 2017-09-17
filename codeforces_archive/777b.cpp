#include <bits/stdc++.h>

using namespace std;

int compareChar(const void* a, const void* b)
{
    char int_a = * ((int*) a);
    char int_b = * ((int*) b);

    return int_a - int_b;
}


int main()
{
    int n;
    scanf("%d", &n);

    char sher[1000];
    char mort[1000];

    scanf("%s", sher);
    scanf("%s", mort);

    qsort(sher, n, 1, compareChar);
    qsort(mort, n, 1, compareChar);

    
    int si = 0, mi = 0;

    while(si < n && mi < n)
    {
        if(mort[mi] >= sher[si])
        {
            ++si;    
        }
        ++mi;
    }

    cout << n - si << endl;

    
    si = 0, mi = 0;

    while(si < n && mi < n)
    {
        if(mort[mi] > sher[si])
        {
            ++si;    
        }
        ++mi;
    }

    cout << si << endl;    

    return 0;
}

