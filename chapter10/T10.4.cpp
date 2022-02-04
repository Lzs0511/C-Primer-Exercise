#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    vector<double> vec(10, 10.1);

    double sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum << endl;
    return 0;
}