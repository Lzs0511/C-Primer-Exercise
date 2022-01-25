#include<iostream>
#include<cassert>
using namespace std;

void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
        cerr << __func__ << ": array size is " << size << endl;
    #endif
}
int main()
{
    int i = 1; 
    print(&i, 1);
    return 0;   
}