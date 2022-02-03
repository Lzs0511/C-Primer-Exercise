#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;
    vec.push_back(1);
    cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;
    for(int i = 2; i <= 20; ++i)
    {
        vec.push_back(i);
        cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;
    }
    vec.reserve(50);
    cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;
    while(vec.size() != vec.capacity())
    {
        vec.push_back(vec.size());
    }
    cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;
    vec.push_back(vec.size());
    cout << "size: " << vec.size() << " " << "capacity: " << vec.capacity() << endl;

    return 0;
}