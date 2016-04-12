//652d_6.cpp

//==================================================================================
// Fenwick Tree Sum
//==================================================================================

vector<int> fenwickT;
int fenwickN;

void fenwickInit (int nn)
{
    fenwickN = nn;
    fenwickT.assign(fenwickN, 0);
}

void fenwickInc (int i, int delta)
{
    for (; i < fenwickN; i = (i | (i+1)))
        fenwickT[i] += delta;
}

void fenwickInit (vector<int> a)
{
    fenwickInit ((int) a.size());
    for (unsigned i = 0; i < a.size(); i++)
        fenwickInc(i, a[i]);
}

int fenwickSum (int r)
{
    int result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += fenwickT[r];
    return result;
}

int fenwickSum (int l, int r)
{
    return fenwickSum(r) - fenwickSum(l-1);
}

//==================================================================================
// Fenwick Tree Sum
//==================================================================================
