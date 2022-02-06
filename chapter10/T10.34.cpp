#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    for(int i = 0; i < 100; ++i)vec.push_back(i);
    for(auto iter = vec.crbegin(); iter != vec.crend(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}