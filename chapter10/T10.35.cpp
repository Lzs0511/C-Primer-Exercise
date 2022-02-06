#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    for(int i = 1; i != 101; ++i)vec.push_back(i);
    for(auto iter = vec.cend() - 1; iter >= vec.cbegin(); --iter)
    {
        cout << * iter << " ";
    }
    cout << endl;
    return 0;
}