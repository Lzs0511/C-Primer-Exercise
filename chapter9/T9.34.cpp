#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    vector<int> vec(20, 3);
    vec.resize(30, 2);
    auto iter = vec.begin();
    while(iter != vec.end())
    {
        if(*iter % 2)
            iter = vec.insert(iter, *iter);
    }
    ++iter;
    return 0;
}