#include<iostream>
#include<vector>
#include<list>
using namespace std;
list<int> l1{1, 2, 3, 4, 5};
vector<int> v1{2, 3, 4, 5};
int main()
{
    vector<int> v2(l1.begin(), l1.end());
    cout << (v1 < v2) << endl;
    return 0;
}