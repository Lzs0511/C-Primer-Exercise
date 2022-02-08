#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
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

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn() < s2.isbn();
}

int main()
{
    using pf = bool (*)(const Sales_data &s1, const Sales_data &s2);
    // multiset<Sales_data, bool (*)(const Sales_data &s1, const Sales_data &s2)> bookstore(compareIsbn);
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);
    // multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

    return 0;
}