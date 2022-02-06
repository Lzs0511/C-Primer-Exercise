#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 5, 4, 7, 8 , 7, 6, 5, 7, 6, 3, 10};

    vector<int> vec1;

    sort(vec.begin(), vec.end());
    // back_insert_iterator<vector<int>> ins = back_inserter(vec1);
    auto ins = back_inserter(vec1);
    unique_copy(vec.cbegin(), vec.cend(), ins);

    for(auto x: vec1)cout << x << endl;
    return 0;   
}