#include <iostream>
#include <string>
using namespace std;
struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data& combine(const Sales_data &rhs);
    string isbn();
};
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}
string Sales_data::isbn()
{
    return this->bookNo;
}

int main()
{
    struct Sales_data data1;

    if (cin >> data1.bookNo >> data1.units_sold >> data1.revenue)
    {
        struct Sales_data data2;
        while (cin >> data2.bookNo >> data2.units_sold >> data2.revenue)
        {
            if (data1.isbn() == data2.isbn())
            {
                data1.combine(data2);
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