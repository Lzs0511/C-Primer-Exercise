#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    vector<string> vec;
    for(int i = 0; i <= 100; ++i)
    {
        vec.push_back(to_string(i));
    }
    int sum = 0;
    for(auto str: vec)
    {
        sum += stoi(str);
    }
    cout << sum << endl;
    return 0;
}