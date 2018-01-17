#include <iostream>

using namespace std;

int main()
{
    unsigned long long int n, k;

    cin >> n >> k;

    if (k == 1)
    {
        cout << n << endl;
    }
    else
    {
        unsigned long long int f = 1ULL;

        while (f < n)
        {
            n |= f;
            f <<= 1ULL;
        }

        cout << n << endl;
    }

    return 0;
}