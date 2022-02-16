#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    string input;
    cin >> input;
    size_t len = input.size() + 1;
    char *str = new char[len]();
    strcpy(str, input.c_str());
    cout << str << endl;
    return 0;
}