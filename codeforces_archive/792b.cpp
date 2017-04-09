#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int nKids, nSteps;

    cin >> nKids >> nSteps;

    list<int> kids;

    for(int i = 1; i <= nKids; ++i)
    {
        kids.push_back(i);
    }

    int curPos = 0;

    for(int i = 0; i < nSteps; ++i)
    {
        int count;
        cin >> count;

        int nextKid = (curPos + count) % kids.size();

        list<int>::iterator iter = kids.begin();
        for(int k = 0; k < nextKid; ++k, ++iter);

        cout << *iter << " ";

        kids.erase(iter);
        curPos = nextKid % kids.size();
    }

    cout << endl;

    return 0;
}


