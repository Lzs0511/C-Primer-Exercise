#include<iostream>
using namespace std;
void reset(int &i)
{
    i = 100;
}
int main()
{
    int x = 1000;
    reset(x);
    cout << x << endl;
    return 0;
}