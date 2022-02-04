#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec(100, 10);
    fill_n(vec.begin(), vec.size(), 0);
    for(auto x: vec)cout << x << endl;
    return 0;
}