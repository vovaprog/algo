#include <bits/stdc++.h>

using namespace std;

uint64_t a[2][5000] = { 0 };

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    const uint64_t modul = 1000000007;

    uint64_t curVars = 1, prevVars = 1;
    char prev = 0, prevPrev = 0;

    int rowSrc = 0, rowDst = 1;
    int numVars = 1, addVars = 0;
    int maxLevel = 0;

    a[rowSrc][0] = 1;

    uint64_t sum = 0;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        cin >> s;

        if (prev == 's')
        {
            sum = 0;

            for (int i = 0; i < numVars; ++i)
            {
                sum = (sum + a[rowSrc][i]);
            }

            for (int i = 0; i < numVars + addVars; ++i)
            {
                a[rowDst][i] = sum % modul;
                if (i - addVars >= 0)
                {
                    sum -= a[rowSrc][i - addVars];
                }
            }

            numVars += addVars;
            addVars = 0;

            int temp = rowSrc;
            rowSrc = rowDst;
            rowDst = temp;

            for (int i = 0; i < numVars; ++i)
            {
                a[rowDst][i] = 0;
            }
        }
        else if (prev == 'f')
        {
            ++addVars;
        }

        prevPrev = prev;
        prev = s[0];
    }

    sum = 0;

    for (int j = 0; j < numVars; ++j)
    {
        sum = (sum + a[rowSrc][j]) % modul;
    }

    cout << sum << endl;

    return 0;
}
