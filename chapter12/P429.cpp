#include<iostream>
#include<memory>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec(10, 1);
    allocator<int> alloc;
    auto p = alloc.allocate(vec.size() * 2);
    auto q = uninitialized_copy(vec.begin(), vec.end(), p);
    auto end = uninitialized_fill_n(q, vec.size(), 11);
    int num = 0;
    for(auto i = p; i != end; i++){
        cout << *i << endl;
    }
    return 0;
}