#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

int main()
{
    string author, writtings;
    map<string, set<string>> m1;
    map<string, multiset<string>> m2;
    while(cout << "输入作者名和作品名：", cin >> author >> writtings)
    {
        m1[author].insert(writtings);
    }
    // for(const auto &x: m1)
    // {
    //     m2[x.first].insert(x.second);
    // }
    cout << endl;
    for(auto auth: m1)
    {
        cout << "作家：" << auth.first << endl;
        for(auto writ: auth.second)
        {
            cout << "著作：" << writ << endl;
        }
    }
    return 0;
}