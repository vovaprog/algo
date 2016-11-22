#include <bits/stdc++.h>

using namespace std;

typedef long long int int64;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << std::setprecision(std::numeric_limits<double>::max_digits10);
    //cin.getline(s, 100010);    
    
    int num2, num3, num5, num6;
    int sum = 0;

    cin >> num2 >> num3 >> num5 >> num6;

    int f256 = min(min(num2, num5), num6);
    sum += 256 * f256;
    num2 -= f256;
    num5 -= f256;
    num6 -= f256;

    int f32 = min(num2, num3);

    sum += 32 * f32;

    cout << sum << endl;
    
    return 0;
}
