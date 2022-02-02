#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    for(int i = 0; i < 10; i++)vec.push_back(i);

    auto iter = vec.erase(vec.begin(), vec.begin()+1);
    while(iter != vec.end())
    {
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}