#include <bits/stdc++.h>

using namespace std;

int buf[1000][1000];
struct Data
{
    int fa = -1, la = -1;
};

Data rowAs[1000], colAs[1000];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int nRows, nCols;

    cin >> nRows >> nCols;

    for(int i = 0; i < nRows; ++i)
    {
        for(int j = 0; j < nCols; ++j)
        {
            cin >> buf[i][j];

            if(buf[i][j] != 0)
            {
                rowAs[i].la = j;
                if(rowAs[i].fa < 0)
                {
                    rowAs[i].fa = j;
                }
                colAs[j].la = i;
                if(colAs[j].fa < 0)
                {
                    colAs[j].fa = i;
                }
            }
        }
    }

    int result = 0;

    for(int i = 0; i < nRows; ++i)
    {
        for(int j = 0; j < nCols; ++j)
        {
            if(buf[i][j] == 0)
            {
                if(colAs[j].fa >= 0 && i > colAs[j].fa) ++result;
                if(colAs[j].la >= 0 && i < colAs[j].la) ++result;
                if(rowAs[i].fa >= 0 && j > rowAs[i].fa) ++result;
                if(rowAs[i].la >= 0 && j < rowAs[i].la) ++result;
            }
        }
    }

    cout << result << endl;

    return 0;
}


