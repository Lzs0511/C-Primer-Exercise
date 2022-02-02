#include<iostream>
#include<string>
#include<list>
using namespace std;
list<int> list1;
int main()
{
    for(int i = 0; i != 10; ++i)
    {
        list1.push_back(i);
    }
    list<int>::iterator iter1 = list1.begin(), iter2 = list1.end();

    while(iter1 != iter2)
    {
        cout << *iter1 << endl;
        iter1++;
    }
    return 0;
}