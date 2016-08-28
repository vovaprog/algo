#include <bits/stdc++.h>

using namespace std;

struct Road
{
    Road(int to, int length): to(to), length(length) {}
    int to;
    int length;
};

bool stores[100100] = {false};
vector<Road> roads[100100];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int nTowns, nRoads, nStores;

    cin >> nTowns >> nRoads >> nStores;

    if (nStores < 1)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < nRoads; ++i)
    {
        int t0, t1, l;
        cin >> t0 >> t1 >> l;
        --t0;
        --t1;
        roads[t0].emplace_back(t1, l);
        roads[t1].emplace_back(t0, l);
    }

    for (int i = 0; i < nStores; ++i)
    {
        int store;
        cin >> store;
        --store;
        stores[store] = true;
    }

    int curMin = INT_MAX;
    bool found = false;

    for (int i = 0; i < nTowns; ++i)
    {
        if (stores[i])
        {
            for (auto &r : roads[i])
            {
                if (!stores[r.to] && r.length < curMin)
                {
                    curMin = r.length;
                    found = true;
                }
            }
        }
    }

    if (found)
    {
        cout << curMin << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
