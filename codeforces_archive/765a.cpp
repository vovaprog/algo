#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char bhome[10];

    scanf("%d", &n);
    scanf("%s", bhome);

    std::string home(bhome);

    std::map<std::string, int> fs;

    for(int i = 0; i < n; ++i)
    {
        char bAll[20];
        char bfrom[10], bto[10];
        scanf("%s", bAll);
        strncpy(bfrom, bAll, 3);
        bfrom[3] = 0;
        strncpy(bto, bAll + 5, 3);
        bto[3] = 0;

        std::string from(bfrom), to(bto);

        std::string directFlight = from + "->" + to;
        std::string backFlight = to + "->" + from;

        if(fs[backFlight] == 0)
        {
            ++fs[directFlight];
        }
        else
        {
            --fs[backFlight];
        }
    }

    for(auto &p : fs)
    {
        if(p.second > 0)
        {
            printf("contest");
            return 0;
        }
    }

    printf("home");

    return 0;
}


