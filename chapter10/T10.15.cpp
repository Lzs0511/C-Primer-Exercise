#include<iostream>
using namespace std;

int main()
{
    int n = 100;
    auto f = [n](int x)->int{return n + x;};
    cout << f(100) << endl;
    return 0;
}