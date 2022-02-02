#include<iostream>
#include<vector>
using namespace std;
using vint = vector<int>;

int main()
{
    vint v1;
    const vint v2;
    auto it1 = v1.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin(), it2 = v2.begin();
    return 0;
}