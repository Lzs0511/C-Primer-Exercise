#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>vec, int idx)
{
    if(idx < 0)return ;
    print(vec, idx - 1);
    cout << vec[idx] << endl;
    // print(vec, 0);
    // return ;
}
int main()
{
    vector<int> vec;
    for(size_t i = 0; i != 10; ++i)vec.push_back(i);
    print(vec, vec.size() - 1);
    return 0;
}