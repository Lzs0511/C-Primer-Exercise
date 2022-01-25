#include<vector>
#include<iostream>
using namespace std;
typedef int(*func)(int, int);
using func1 = int(*)(int, int);
int mul(int x, int y)
{
    return x * y;
}
int main()
{
    // 第一种写法
    // vector<int(*)(int, int)> vec; 
    // 第二种写法
    // vector<decltype(mul) *>vec;
    // 第三种写法
    // vector<func> vec;
    // 第四种写法
    vector<func1> vec;
    vec.push_back(mul);
    cout << vec[0](100, 20) << endl;
    return 0;
}