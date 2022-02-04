#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    const string str = "interesting";
    string input;
    list<string> l1;
    while(cin >> input)
    {
        l1.push_back(input);
    }

    cout << "count is:" << count(l1.cbegin(), l1.cend(), str) << endl;
    return 0;
}