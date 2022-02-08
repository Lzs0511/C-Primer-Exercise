#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    map<string, vector<string>> families;

    families["zhang"].push_back("张三");
    families["zhang"].push_back("张四");
    for(auto x: families)
    {
        cout << x.first << "家有:";
        for(auto name: x.second)cout << name << " ";
        cout << endl;
    }

    return 0;
}