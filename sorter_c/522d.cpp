#include <bits/stdc++.h>

using namespace std;

#define debug(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

template <class TMap, class TKey, class TValue>
inline bool tryGetValue(TMap &m, TKey &key, TValue &u)
{
    auto it = m.find(key);
    if (it != m.end())
    {
        u = it->second;
        return true;
    }
    return false;
}

struct Pair
{
    int start, end;
    Pair(int start, int end): start(start), end(end)
    {}
    Pair()
    {}
}
;

bool operator<(const Pair &p0, const Pair &p1)
{
    return p0.end < p1.end;
}

int main()
{
    int sz, nRequests;
    int buf[100000];

    scanf("%d %d", &sz, &nRequests);

    for (int i = 0;i < sz;i++)
    {
        scanf("%d", &buf[i]);
    }

    map<int, int> m;
    map<int, Pair> pairs;
    int val;
    int lastPairs[100000];
    int lastPair = -1;

    for (int i = 0;i < sz;i++)
    {
        if (tryGetValue(m, buf[i], val))
        {
            pairs[i] = Pair(val, i);
            lastPair = i;
        }
        lastPairs[i] = lastPair;
        m[buf[i]] = i;
    }

    for (auto& p : pairs)
    {
        debug("<%d %d>", p.second.start, p.second.end);
    }

    debug("[%d]", pairs.size());

    for (int q = 0;q < nRequests;q++)
    {
        int start, end;

        scanf("%d %d", &start, &end);
        --start;
        --end;



        auto iter = pairs.find(lastPairs[end]);

        debug("=======%d", lastPairs[end]);
        debug("-------%d %d", iter->second.start, iter->second.end);



        if (iter == pairs.end())
        {
            printf("-1\n");
        }
        else
        {
            //auto riter = map<int,Pair>::reverse_iterator(iter);

            //debug("+++++++%d %d",riter->second.start,riter->second.end);

            int minDist = 2000000000;

            bool exitLoop = false;
            while (!exitLoop)
            {
                debug("///// %d %d", iter->second.start, iter->second.end);

                if (iter->second.start >= start)
                {
                    minDist = min(minDist, iter->second.end - iter->second.start);
                }

                if (iter == pairs.begin())
                    exitLoop = true;
                --iter;
            }



            if (minDist == 2000000000)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", minDist);
            }
        }

        /*        Pair p{start,end};
                auto iter = upper_bound(pairs.begin(), pairs.end(),p);
                        
                int i = iter - pairs.begin() - 1;
                
                
                
                for(;i>=0 && pairs[i].end>start;i--)
                {
                    if(pairs[i].start>=start)
                    {
                        minDist = min(minDist, pairs[i].end - pairs[i].start);
                    }            
                }
                
                if(minDist==2000000000)
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n",minDist);
                }*/
    }

    return 0;
}
