#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main()
{
    multimap<string, string> families;
    int i = 0;
    int j = 1;
    for(string first, last; cout << i << endl,cin >> last >> first; cout << j << endl, families.emplace(last, first));
    {
        // families.insert({last, first});
    }
    for(const auto &family: families)
    {
        cout << family.first << ", " << family.second << endl;
    }
    return 0;
}