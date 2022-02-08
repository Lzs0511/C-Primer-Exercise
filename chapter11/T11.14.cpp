#include<iostream>
#include<map>
#include<utility>
#include<vector>
using namespace std;

using PSS = pair<string, string>;

int main()
{
    map<string, vector<PSS>> families;

    string family;
    string birthday, name;
    while(cin >> family)
    {
        
        while(cout << "请输入名字和生日:", cin >> name >> birthday)
        {
            families[family].push_back({name, birthday});
        }
    }

    for(auto family: families)
    {
        // cout << "姓：" << family.first << " ";
        for(auto name_bir: family.second)
        {
            cout << "姓名:" << name_bir.first << ", 生日:" << name_bir.second << endl;
        }
    }
    return 0;
}