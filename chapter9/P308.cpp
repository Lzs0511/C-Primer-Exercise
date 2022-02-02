#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    cout << vec.size() << endl;
    vec.emplace_back();
    cout << vec.size() << endl;
    cout << *vec.begin() << endl;
    return 0;
}