#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<iterator>
using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> l1;
    copy(vec.crbegin() + 3, vec.crend() - 2, back_inserter(l1));
    for(auto x: l1)cout << x << endl;
    return 0;    
}