// #include<iostream>
// #include<string>
// using namespace std;


// class Sales_data
// {
//     public:
//     Sales_data(std::string s = ""): bookNo(s){}

//     Sales_data(std::string s, unsigned cnt, double rev):
//         bookNo(s), units_sold(cnt), revenue(rev*cnt){}
    
//     Sales_data(std::istream &is){}
//     private:
//     string bookNo;
//     unsigned units_sold;
//     double revenue;
// };


#include <iostream>
#include <string>
using namespace std;
struct Sales_data;
istream &read(istream &is, Sales_data &data);
class Sales_data
{
    friend istream &read(istream &is, Sales_data &data);
    friend ostream &print(ostream &os, const Sales_data &data);
    public:
    // 创建构造函数
    
    Sales_data(const string &s, unsigned int _units_sold, double _revenue):bookNo(s), 
        units_sold(_units_sold), revenue(_revenue * _units_sold){ cout << "构造函数3" << endl; } // 构造函数3
    Sales_data(istream &is = std::cin)//构造函数4
    {
    // cout << "构造函数4" << endl;
    read(is, *this);
    } 
    // 默认构造函数
    // Sales_data(string s = ""):bookNo(s){}  // 构造函数1
    Sales_data &combine(const Sales_data &rhs);
    string isbn();

    // private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    
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

void printSales_data(const Sales_data&);
Sales_data first_item;
int main()
{
    
    printSales_data(first_item);
}

void printSales_data(const Sales_data &item)
{
    cout << item.bookNo << " " << item.units_sold << " " << item.revenue << endl;
}