#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    std::vector<int> v;
    cout << v.size() << endl;
    v[0] = 1;
    cout << "v0==" << v[0] << endl;
    // cout << v.size() << endl;
    return 0;
}