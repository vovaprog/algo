#include <bits/stdc++.h>

using namespace std;

class  Quorum{
public:
    int count(vector <int> arr, int k)
    {
        sort(arr.begin(),arr.end());

        return accumulate(arr.begin(),arr.begin()+k,0);
    }
};


int main()
{
    vector<int> input = {50,2,9,49,38};
    Quorum q;
    cout <<q.count(input, 3)<<endl;
}
