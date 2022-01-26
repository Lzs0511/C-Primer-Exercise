#include <iostream>
#include <string>
using namespace std;
struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data& combine(const Sales_data &rhs);
    string& isbn();
};
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}
string& Sales_data::isbn()
{
    return this->bookNo;
}

int main()
{
    Sales_data data1;
    data1.bookNo = "Hee";
    data1.isbn() = "asd";
    // cout << as << endl;
    // as = "Heee";
    cout << data1.bookNo << endl;
    // cout << as << endl;
    return 0;
}