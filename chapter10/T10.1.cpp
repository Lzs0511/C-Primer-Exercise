#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    constexpr int x = 100;
    int n;
    while(cin >> n)
    {
        vec.push_back(n);        
    }
    cout << "count is: " << count(vec.cbegin(), vec.cend(), x) << endl;
    return 0;
}