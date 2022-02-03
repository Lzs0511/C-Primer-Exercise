#include<iostream>
#include<forward_list>
#include<list>
using namespace std;

int main()
{
    forward_list<int> flist{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    forward_list<int>::iterator prev = flist.before_begin();
    forward_list<int>::iterator curr = flist.begin();
    while(curr != flist.end())
    {
        if(*curr % 2)
        {
            curr = flist.erase_after(prev);
        }else
        {
            prev = curr;
            ++curr;
        }
    }
    for(auto x: flist)
    {
        cout << x << endl;
    }
    return 0;
}