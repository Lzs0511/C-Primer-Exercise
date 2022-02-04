#include<iostream>
#include<string>
using namespace std;
int main()
{
    auto f = [](int a, int b)->int {return a + b;};
    cout << f(19, 20) << endl;
    return 0;
}