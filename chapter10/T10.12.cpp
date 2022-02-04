#include <iostream>
#include<vector>
#include<algorithm>
#include <string>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data &combine(const Sales_data &rhs);
    string isbn() const;
};
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}
string Sales_data::isbn() const
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

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn() > s2.isbn();
}

int main()
{
    vector<Sales_data> vec{{"123", 1, 2}, {"124", 2, 3}, {"125", 2, 3}};
    sort(vec.begin(), vec.end(), compareIsbn);
    for(auto x: vec)
    {
        cout << x.isbn() << endl;
    }
    return 0;
}