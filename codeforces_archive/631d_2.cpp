#include <bits/stdc++.h>

using namespace std;

#define debug(args...) //printf(args);
#define debug2(fmt,args...) //printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

struct Block
{
    int64 count;
    char c;
};

vector<Block> tbs, sbs;

int64 compareOne(int64 tInd)
{
    if (tbs[tInd].c == sbs[0].c && tbs[tInd].count >= sbs[0].count)
    {
        int64 res = tbs[tInd].count - sbs[0].count + 1;
        if (res > 0)
            return res;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}

bool equalBlocksP(vector<Block> &p, int ind0, int ind1)
{
    if (ind1 == 0 || ind1 == p.size() - 1)
        swap(ind0, ind1);

    if (ind0 == 0 || ind0 == p.size() - 1)
    {
        if (p[ind0].c == p[ind1].c &&
                p[ind0].count <= p[ind1].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (p[ind0].c == p[ind1].c &&
                p[ind0].count == p[ind1].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool equalBlocks(vector<Block> &s, int indS, vector<Block> &p, int indP)
{
    if (indP == 0 || indP == p.size() - 1)
    {
        if (s[indS].c == p[indP].c &&
                s[indS].count >= p[indP].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (s[indS].c == p[indP].c &&
                s[indS].count == p[indP].count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


//==============================================================================
//======================== Knuth–Morris–Pratt search ===========================
//==============================================================================

int* knuthPrefixFunction(vector<Block> &p)
{
    int n = (int)p.size();
    int *pi = new int[n];
    pi[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && !equalBlocksP(p, i, j))
        {
            j = pi[j - 1];
        }
        if (equalBlocksP(p, i, j))
        {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}


int knuthSearch(vector<Block> &s, vector<Block> &p)
{
    int counter = 0;

    int *d = knuthPrefixFunction(p);
    int k = 0;

    int i, j;
    for (i = 0, j = 0;i < s.size() && j < p.size();++i)
    {
        while (j > 0 && !equalBlocks(s, i, p, j))
        {
            j = d[j - 1];
        }
        if (equalBlocks(s, i, p, j))
        {
            j++;
        }
        if (j == p.size())
        {
            counter++;
            j = d[j - 1];
        }
    }

    delete[] d;
    return counter;
}

//==============================================================================
//======================== Knuth–Morris–Pratt search ===========================
//==============================================================================


int main()
{
    int tSize, sSize;

    scanf("%d %d", &tSize, &sSize);

    tbs.reserve(tSize);
    sbs.reserve(sSize);

    Block prevB;

    for (int i = 0;i < tSize;i++)
    {
        int cnt;
        Block b;
        scanf("%d-%c", &cnt, &b.c);
        b.count = cnt;

        if (i > 0 && prevB.c == b.c)
        {
            tbs[tbs.size() - 1].count += b.count;
        }
        else
        {
            tbs.push_back(b);
        }

        prevB = b;
    }

    for (int i = 0;i < sSize;i++)
    {
        Block b;
        scanf("%d-%c", &b.count, &b.c);

        if (i > 0 && prevB.c == b.c)
        {
            sbs[sbs.size() - 1].count += b.count;
        }
        else
        {
            sbs.push_back(b);
        }

        prevB = b;
    }

    int64 counter = 0;

    if (sbs.size() < 2)
    {
        for (int i = 0;i < tbs.size();i++)
        {
            counter += compareOne(i);
        }
    }
    else
    {
        counter = knuthSearch(tbs, sbs);
    }

    cout << counter;

    return 0;
}
