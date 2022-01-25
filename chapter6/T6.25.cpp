#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
    string str = string(argv[1]) + argv[2];
    cout << str << endl;
    return 0;
}