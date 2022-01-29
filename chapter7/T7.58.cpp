#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Example
{
    public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};
vector<double> Example::vec(vecSize);
// double const Example::rate = 6.5;