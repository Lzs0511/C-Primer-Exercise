#include<iostream>
using namespace std;

class Y;
class X;

class Y
{
    X *x;
};
class X
{
    Y *y;
};
int main()
{
    return 0;
}