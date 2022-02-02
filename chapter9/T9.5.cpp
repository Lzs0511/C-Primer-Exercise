#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

vector<int>::const_iterator findX(vector<int>::const_iterator beg, vector<int>::const_iterator end, int x)
{
    while(beg != end)
    {
        if(*beg == x)return beg;
        beg++;
    }
    return end;
}
int main()
{
    vector<int> vec;
    srand(time(NULL));
    for(int i = 0; i < 100; ++i)
    {
        vec.push_back(rand() % 100);
    }
    int x = 75;
    vector<int>::const_iterator iter = findX(vec.cbegin(), vec.cend(), x);
    if(iter != vec.cend()) cout << *iter << endl;
    return 0;
}