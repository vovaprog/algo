#include <bits/stdc++.h>

using namespace std;

vector<int> towns[100000];

set<int> imps[100000];
vector<int> impsByTown[100000];

int ans[100000] = {0};
int impossible[100000] = {0};

int nPlans;

#define debug(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

set<int> stopped[100000];

set<int>* walkTree(int cur, int parent)
{
    set<int> *nextSet = new set<int>();

    for (auto& link : towns[cur])
    {
        if (link == parent)
            continue;

        set<int> *rs = walkTree(link, cur);

        if (rs->size() > nextSet->size())
        {
            swap(nextSet, rs);
        }

        for (auto &r : *rs)
        {
            if (imps[r].count(cur) != 0)
            {
                ans[r]++;
            }
            else
            {
                if (nextSet->count(r) == 0)
                {
                    nextSet->insert(r);
                }
                else
                {
                    stopped[cur].insert(r);
                }
            }
        }

        delete rs;
    }

    for (auto &r : stopped[cur])
    {
        ans[r]++;
        nextSet->erase(r);
    }

    for (auto &r : impsByTown[cur])
    {
        if (nextSet->count(r))
        {
            ans[r]++;
        }
        nextSet->insert(r);
    }

    return nextSet;
}

int main()
{
    int nTowns, imp;

    scanf("%d", &nTowns);

    for (int i = 0;i < nTowns - 1;i++)
    {
        int t0, t1;
        scanf("%d %d", &t0, &t1);
        --t0;
        --t1;
        towns[t0].push_back(t1);
        towns[t1].push_back(t0);
    }

    scanf("%d", &nPlans);

    for (int q = 0;q < nPlans;q++)
    {
        int nImp;
        scanf("%d", &nImp);

        for (int i = 0;i < nImp;i++)
        {
            scanf("%d", &imp);
            --imp;
            imps[q].insert(imp);
            impsByTown[imp].push_back(q);

            const auto &impsEnd = imps[q].end();

            for (auto &t : towns[imp])
            {
                if (imps[q].find(t) != impsEnd)
                {
                    impossible[q] = 1;
                    break;
                }
            }
        }
    }

    walkTree(0, 0);

    for (int i = 0;i < nPlans;i++)
    {
        if (impossible[i])
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}

