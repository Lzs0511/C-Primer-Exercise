#include<iostream>
#include<string>
using namespace std;
void f()
{
    printf("f()\n");
}
void f(int x)
{
    printf("f(int)\n");
}
void f(int x, int y)
{
    printf("f(int, int)\n");
}
void f(double x, double y = 3.14)
{
    printf("f(double, double)\n");
}
void f(double x, double y, double z)
{
    printf("f(double, double, double)\n");
}

int main()
{

    // f(2.56, 42); // 具有二义性
    f(52);
    f(42, 0);
    f(2.56, 3.14);
    f(3.14, 4.2, 10);
    
}