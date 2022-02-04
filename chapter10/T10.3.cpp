#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
    vector<int> vec(10, 10);

    int sum = accumulate(vec.cbegin(), vec.cend(), 0.0);
    cout << "sum: " << sum << endl;
    return 0;
}