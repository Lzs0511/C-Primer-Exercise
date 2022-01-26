#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data &combine(const Sales_data &rhs);
    string isbn();
};
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}
string Sales_data::isbn()
{
    return this->bookNo;
}

istream &read(istream &is, Sales_data &data)
{
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold * price;
    return is;
}

ostream &print(ostream &os, const Sales_data &data)
{
    os << data.bookNo << " " << data.units_sold << " " << data.revenue;
    return os;
}

int main()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data data;
        while (read(cin, data))
        {
            if (total.isbn() == data.isbn())
            {
                total.combine(data);
            }
            else
            {
                print(cout, total);
                total = data;
            }
        }
        print(cout, total);
    }
    else
    {
        cerr << "Error!" << endl;
    }
}