#include <iostream>
#include <vector>
#include <list>
using namespace std;

list<int> l1{1, 2, 3, 4, 5};
vector<int> v1{1, 2, 3, 4, 5};
vector<double> vecd(l1.begin(), l1.end());
vector<double> vecd2(v1.begin(), v1.end());
int main()
{
    for(auto x: vecd)
    {
        cout << x << endl;
    }
    cout << "----------------------------" << endl;
    for(auto x: vecd2)
    {
        cout << x << endl;
    }
    return 0;
}
