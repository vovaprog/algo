#include <bits/stdc++.h>

using namespace std;

#define debug(args...) printf(args);
#define debug2(fmt,args...) printf(fmt,args);printf("   (%s)\n",#args);

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long int int64;

int links[30];
int back_links[30];
bool exists[30] = {false};
bool visited[30] = {false};

inline int toIndex(char c)
{
    return (int)(c - 'a');
}

inline char toChar(int i)
{
    return (char)(i + 'a');
}

int main()
{
    fill(links, links + 30, -1);
    fill(back_links, back_links + 30, -1);

    int n;

    scanf("%d", &n);

    char s[30];

    while(n--)
    {        
        scanf("%s", s);

        for (int i = 0;s[i] != 0;++i)
        {
            int ch = toIndex(s[i]);
            exists[ch] = true;

            if (s[i + 1] != 0)
            {
                int ch2 = toIndex(s[i + 1]);
                links[ch] = ch2;
                back_links[ch2] = ch;
            }
        }
    }

    string output;

    forn(i, 26)
    {
        if (exists[i] && !visited[i])
        {
            int start = i;

            while (back_links[start] >= 0)
            {
                start = back_links[start];
            }

            do
            {
                output += toChar(start);
                visited[start] = true;
                start = links[start];
            }
            while (start >= 0);
        }
    }

    printf("%s\n", output.c_str());

    return 0;
}
