#include <iostream>
#include <string>
using namespace std;
struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    struct Sales_data data1;

    if (cin >> data1.bookNo >> data1.units_sold >> data1.revenue)
    {
        struct Sales_data data2;
        while (cin >> data2.bookNo >> data2.units_sold >> data2.revenue)
        {
            if (data1.bookNo == data2.bookNo)
            {
                data1.units_sold += data2.units_sold;
                data1.revenue += data2.revenue;
            }
            else
            {
                cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << endl;
                data1 = data2;
            }
        }
        cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << endl;
    }
    else
    {
        cerr << "No data!?" << endl;
    }
}