#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct NoDefault
{
    int a;
    NoDefault(int _a):a(_a){}
    // NoDefault();
};
// NoDefault::NoDefault()
// {
//     cout << "123" << endl;
// }
class C
{
    NoDefault t;
    
};
int main()
{
    
    // vector<NoDefault> vec(10);
    vector<C> vec(10);
    return 0;
}