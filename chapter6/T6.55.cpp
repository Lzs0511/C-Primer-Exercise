#include<vector>
#include<iostream>
using namespace std;
typedef int (*func)(int, int);
int mul(int x, int y)
{
    return x * y;
}
int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int divide(int x, int y)
{
    if(y == 0)
    {
        cerr << "div can't be zero" << endl;
        exit(1);
    }
    return x / y;
}
int main()
{
    vector<func> vec;
    vec.push_back(divide);
    vec.push_back(add);
    vec.push_back(mul);
    vec.push_back(sub);

    for(int i = 0; i < 4; ++i)
    {
        int x = 10000, y = 1000;
        int ret = vec[i](x, y);
        cout << ret << endl;
    }
    return 0;
}