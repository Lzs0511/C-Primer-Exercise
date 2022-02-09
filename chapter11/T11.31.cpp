#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
    multimap<string, string> map1{{"a1", "aa"}, {"a2", "bb"}, {"a3", "cc"}};

    string name;
    
    while(cin >> name)
    {
        if(map1.find(name) != map1.end())
        {
            map1.erase(name);
        }
    }
    for(auto str: map1) cout << str.first << ", value:" << str.second << endl;
    return 0;
}