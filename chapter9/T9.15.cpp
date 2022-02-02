#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> vec(10, 20);
    vector<int> vec2(10, 1);
    cout << (vec < vec2) << endl;
    return 0;
}