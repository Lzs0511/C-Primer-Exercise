#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

bool findX(vector<int>::const_iterator beg, vector<int>::const_iterator end, int x)
{
    while(beg != end)
    {
        if(*beg++ == x)return true;
        
    }
    return false;
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
    bool isExist = findX(vec.cbegin(), vec.cend(), x);
    cout << isExist << endl;
    return 0;
}