#include<iostream>
using namespace std;

int main()
{
    size_t v1 = 42;
    auto f = [v1]{return v1;};
    v1 = 0;
    auto j = f();
    cout << j << endl;
    return 0;
}