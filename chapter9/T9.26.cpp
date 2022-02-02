#include<iostream>
#include<vector>
#include<list>
using namespace std;
int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

int main()
{
    int size = sizeof(ia) / sizeof(int);
    vector<int> v1(ia, ia+size);
    list<int> l1(ia, ia+size);
    // 删除list中的奇数元素
    auto iter1 = l1.begin();
    while(iter1 != l1.end())
    {
        if(*iter1 % 2)
            iter1 = l1.erase(iter1);
        else 
            ++iter1;
    }

    // 删除vector中的偶数元素
    auto iter2 = v1.begin();
    while(iter2 != v1.end())
    {
        if(*iter2 % 2 == 0)
            iter2 = v1.erase(iter2);
        else 
            ++iter2;
    }

    for(auto x: l1) cout << x << endl;
    cout << "---vector---" << endl;
    for(auto x: v1) cout << x << endl;

    return 0;
}