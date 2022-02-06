#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<list>
#include<deque>
using namespace std;

int main()
{
    vector<int> vec;
    vector<int> vec1;
    list<int> l1;
    deque<int> d1;
    for(int i = 0; i < 9; i++)vec.push_back(i + 1);

    auto ins1 = back_inserter(vec1);
    auto ins2 = front_inserter(l1);
    auto ins3 = inserter(d1, d1.begin());
    copy(vec.begin(), vec.end(), ins1);
    copy(vec.begin(), vec.end(), ins2);
    copy(vec.begin(), vec.end(), ins3);

    for(auto x: vec1)cout << x << " ";
    cout << endl << "------------------------" << endl;
    for(auto x: l1) cout << x << " ";
    cout << endl << "------------------------" << endl;
    for(auto x: d1) cout << x << " ";
    cout << endl;
    return 0;
}