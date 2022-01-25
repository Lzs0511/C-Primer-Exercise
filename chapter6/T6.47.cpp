#include<iostream>
#include<vector>
using namespace std;
using Iter = vector<int>::iterator;
void print(Iter begin, Iter end)
{
    #ifndef NDEBUG
        cerr << __func__ << "(" << *begin << ", " << *end << ")" << endl;
        cerr << "vector size:" << (end - begin) << endl;
    #endif
    if(begin == end)
    {
        cout << "over!" << endl;
        return ;
    }

    printf("%d\n", *begin++);
    print(begin, end);
}
int main()
{
    vector<int> vec;
    for(int i = 0; i != 10; ++i)vec.push_back(i);
    print(vec.begin(), vec.end());
    return 0;
}