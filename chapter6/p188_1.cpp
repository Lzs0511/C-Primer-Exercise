#include<iostream>
using namespace std;
void reset(int *);
int main()
{
    int i = 42;
    reset(&i);
    cout << "i = " << i << endl;
}

void reset(int *ip)
{
    *ip = 0;
    ip = 0;
}