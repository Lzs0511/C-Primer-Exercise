#include<iostream>
#include "strBlob.h"
using namespace std;

int main()
{
    strBlob b1;
    {
        strBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }
    cout << b1.back() << endl;
    return 0;
}