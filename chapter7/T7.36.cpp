#include<iostream>
#include<string>
using namespace std;
struct X
{
    X (int i, int j): base(i), rem(base % j){}
    int rem;
    int  base;
};

int main()
{
    X x(1, 2);
    cout << x.base << " " << x.rem << endl;
    return 0;
}