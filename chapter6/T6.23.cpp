#include<iostream>
#include<iterator>
using namespace std;
// void print(const int *begin, const int *end)
// {
    
//     for(; begin != end; begin++) cout << *begin << " ";
//     puts("");
// }

void print(const int *val, const size_t size){
    for(int i = 0; i != size; ++i)cout << *val++ << ' ';
    puts("");
}
int main()
{
    
    int i = 0, j[2] = {0, 1};
    // print(begin(i), end(i)); // 不能这么使用
    // print(begin(j), end(j));
    print(&i, sizeof i / sizeof(int));
    print(j, sizeof j / sizeof(int));
    return 0;
}