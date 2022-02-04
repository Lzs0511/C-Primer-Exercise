#include<iostream>
using namespace std;

int main()
{
    size_t v = 42;
    auto f = [&v]()->size_t &{return v;};
    f() = 10;
    cout << v << endl;
    return 0;
}