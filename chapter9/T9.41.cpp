#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    vector<char> vec;
    for(int i = 65; i <= 90; ++i)vec.push_back(i);
    // vec.push_back(0);
    string s(vec.begin(), vec.end());
    cout << s << endl;
    return 0;
}