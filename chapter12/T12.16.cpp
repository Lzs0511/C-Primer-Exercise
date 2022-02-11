#include<iostream>
#include<memory>
#include<string>
using namespace std;

int main()
{
    unique_ptr<string> ptr(new string("Hello World"));
    unique_ptr<string> ptr1(ptr);
    // ptr1 = ptr;
    return 0;
}