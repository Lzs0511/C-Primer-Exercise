#include<iostream>
#include<string>
int main()
{
    auto f = [](int a, int b){return a + b;};
    std::cout << f(19, 20) << std::endl;
    return 0;
}