//631d_2

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
