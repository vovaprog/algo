#include <bits/stdc++.h>

using namespace std;

int m[100][100];

int main()
{
    int n, k;

    cin >> n >> k;

    if(k > n * n)
    {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            m[i][j] = 0;
        }
    }

    for(int start = 0; start < n && k > 0; ++start)
    {
        for(int j = start; j < n && k > 0; ++j)
        {
            if (j == start)
            {
                m[start][start] = 1;
                --k;
            }
            else if (k >= 2)
            {
                m[start][j] = 1;
                m[j][start] = 1;
                k -= 2;                
            }            
        }
    }

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

