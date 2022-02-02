#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main()
{
    list<int> l1;
    deque<int> d1, d2;

    for(int i = 0; i != 100; ++i)l1.push_back(i);

    for(auto x: l1)
    {
        if(x % 2)
            d1.push_back(x);
        else
            d2.push_back(x);
    }

    cout << "奇数列表为：" << endl;
    for(auto x: d1)
    {
        cout << x << endl;
    }
    cout << "偶数列表为：" << endl;
    for(auto x: d2)
    {
        cout << x << endl;
    }
    return 0;
}