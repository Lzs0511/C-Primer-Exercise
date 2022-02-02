#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

list<const char*> l1 = {"Hello", "World", "Hello", "C++"};

int main()
{
    vector<string> vec;
    vec.assign(l1.begin(), l1.end());
    for(auto elem: vec)
    {
        cout << elem << endl;
    }
    return 0;
}