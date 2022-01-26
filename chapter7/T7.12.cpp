#include <iostream>
#include <string>
using namespace std;
struct Sales_data;
istream &read(istream &is, Sales_data &data);
struct Sales_data
{
    // 创建构造函数
    Sales_data(const string &s):bookNo(s){ cout << "构造函数2" << endl;} // 构造函数2
    Sales_data(const string &s, unsigned int _units_sold, double _revenue):bookNo(s), 
        units_sold(_units_sold), revenue(_revenue * _units_sold){ cout << "构造函数3" << endl; } // 构造函数3
    Sales_data(istream &is)//构造函数4
    {
    cout << "构造函数4" << endl;
    read(is, *this);
    } 
    // 默认构造函数
    Sales_data() = default;  // 构造函数1
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
//构造函数4
// Sales_data::Sales_data(istream &is)

ostream &print(ostream &os, const Sales_data &data)
{
    os << data.bookNo << " " << data.units_sold << " " << data.revenue;
    return os;
}

int main()
{
    Sales_data total;
    Sales_data data1; // 使用构造函数1
    Sales_data data2("Hello"); // 使用构造函数2
    Sales_data data3("hello", 1, 2); // 使用构造函数3
    Sales_data data4(cin);
    // if (read(cin, total))
    // {
    //     Sales_data data;
    //     while (read(cin, data))
    //     {
    //         if (total.isbn() == data.isbn())
    //         {
    //             total.combine(data);
    //         }
    //         else
    //         {
    //             print(cout, total);
    //             total = data;
    //         }
    //     }
    //     print(cout, total);
    // }
    // else
    // {
    //     cerr << "Error!" << endl;
    // }
}