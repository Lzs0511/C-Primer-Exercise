#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;

bool find1st(const string& str, int n)
{
    return str.size() < n;
}
int main()
{
    string str;
    cin >> str;

    vector<int> vec;
    for(int i = 0; i < 1000; ++i)vec.push_back(i);

    auto res = find_if(vec.begin(), vec.end(), bind(find1st, str, _1));
    cout << *res << endl;
    return 0;
}