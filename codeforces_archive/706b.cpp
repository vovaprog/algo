#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

//=====================================================================
#define debug3(args...) { vector<string> v = splitArgNames(#args); debugPrint(v.begin(), args); }
vector<string> splitArgNames(const string& s)
{
    vector<string> v;
    stringstream ss(s);
    for(string x; getline(ss, x, ',');)
    {
        v.emplace_back(x);
    }
    return move(v);
}
void debugPrint(vector<string>::iterator it)
{
    cout << "\n";
}
template<typename T, typename... Args>
void debugPrint(vector<string>::iterator it, T head, Args... args)
{
    cout << *it << " = " << head << "     ";
    debugPrint(++it, args...);
}
//=====================================================================

typedef long long int int64;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    //cout << std::setprecision(std::numeric_limits<double>::max_digits10);
    //cin.getline(s, 100010);

    int nShops;

    cin >> nShops;

    vector<int> prices;
    prices.reserve(nShops);

    for(int i = 0; i < nShops; ++i)
    {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    sort(prices.begin(), prices.end());

    int nDays;
    cin >> nDays;

    for(int i = 0; i < nDays; ++i)
    {
        int money;
        cin >> money;

        auto iter = upper_bound(prices.begin(), prices.end(), money);
        int dif = distance(prices.begin(), iter);

        cout << dif << endl;
    }

    return 0;
}

