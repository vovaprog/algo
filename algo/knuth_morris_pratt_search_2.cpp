//631d_2

#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

typedef long long int int64;

//==============================================================================
//======================== Knuth–Morris–Pratt search ===========================
//==============================================================================

int* knuthPrefixFunction(const char *p, int pLen)
{
    int *pi = new int[pLen];
    pi[0] = 0;
    for (int i = 1; i < pLen; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (p[i] == p[j])
        {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}


int knuthSearch(const char *s, const char *p, vector<int> &positions)
{
    int sLen = strlen(s);
    int pLen = strlen(p);
    
    int *d = knuthPrefixFunction(p, pLen);
    int k = 0;

    int i, j;
    for (i = 0, j = 0;i < sLen && j < pLen;++i)
    {
        while (j > 0 && s[i] != p[j])
        {
            j = d[j - 1];
        }
        if (s[i] == p[j])
        {
            j++;
        }
        if (j == pLen)
        {
            positions.push_back(i + 1 - pLen);
            j = d[j - 1];
        }
    }

    delete[] d;
    return positions.size();
}

//==============================================================================
//======================== Knuth–Morris–Pratt search ===========================
//==============================================================================

void testKnuthSearch(const char *s, const char *p)
{
    vector<int> positions;
    
    positions.clear();
    knuthSearch(s, p, positions);
    
    debug("%s     %s\n",s,p);
    for_each(positions.begin(),positions.end(),[](int pos){debug("%d ",pos);});printf("\n\n\n");    
}

int main()
{
    testKnuthSearch("bababab","bab");
    testKnuthSearch("hello world","l");
    testKnuthSearch("hello world","d");
    testKnuthSearch("hello world","");
    testKnuthSearch("abcabdabc","abc");
    
    return 0;    
}
