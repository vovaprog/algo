#include <iostream>

using namespace std;

int main_616b()
{
    int nofRows, nofCols;
    cin >> nofRows;
    cin >> nofCols;
    
    int result=-1;
    
    for(int i=0;i<nofRows;i++)
    {
        int rowMin=-1;
        for(int j=0;j<nofCols;j++)
        {
            int v;
            cin >> v;
            if(j==0 || v<rowMin) rowMin=v;
        }
        
        if(i==0 || rowMin>result)
        {
            result = rowMin;
        }
    }
    
    cout << result;
        
    return 0;
}
