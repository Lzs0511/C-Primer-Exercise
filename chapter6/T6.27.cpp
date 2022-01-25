#include<iostream>
#include<initializer_list>
#include<vector>
using namespace std;

int sum(initializer_list<int> ls){
    int ret = 0;
    for(const auto &x : ls) // 单纯用auto 好像也能自动转换成 const int 类型
    {
        ret += x;
        x = 10;
    }
    return ret;
}
int main()
{
    vector<int> vec;
    for(int i = 1; i != 11; ++i)vec.push_back(i);
    int ret = sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    // int ret = sum(vec); //错误, 不能这样写
    cout << ret << endl;

    return 0;
}