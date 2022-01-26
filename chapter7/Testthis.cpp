#include <iostream>
#include <string>
using namespace std;
struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    int test() const
    {
        return 1;
    }
};

int main()
{
    const struct Sales_data t1;
    cout << t1.test() << endl;
}

