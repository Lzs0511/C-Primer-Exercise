#include<iostream>
#include<vector>
using namespace std;
vector<int>::iterator change_val(vector<int>::iterator iter, int x)
{
    return iter;
}
int main()
{
    vector<int> vec;
    for(size_t i = 0; i != 100; i++) vec.push_back(i);
    int x;
    cin >> x;

    change_val(vec.begin(), x);
    return 0;
}