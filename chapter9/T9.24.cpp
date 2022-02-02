#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    for(int i = 0; i < 10; i++)vec.push_back(i);
    cout << "---at---" << endl;
    cout << vec.at(0) << endl;
    cout << "---下标---" << endl;
    cout << vec[0] << endl;
    cout << "---front---" << endl;
    cout << vec.front() << endl;
    cout << "---begin---" << endl;
    cout << *vec.begin() << endl;

    return 0;
}