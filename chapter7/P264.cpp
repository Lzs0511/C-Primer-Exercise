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
    
    explicit Sales_data(const string &s, unsigned int _units_sold, double _revenue):bookNo(s), 
        units_sold(_units_sold), revenue(_revenue * _units_sold)
        { 
            cout << "Sales_data(const string &s, unsigned int _units_sold, double _revenue) 执行了" << endl; 
        } 
    // 委托构造函数 
    Sales_data(): Sales_data("", 0, 0){ cout << "Sales_data() 执行了" << endl;}

    explicit Sales_data(const string &s):Sales_data(s, 0, 0){ cout << "Sales_data(const string &s) 执行了" << endl; }

    explicit Sales_data(istream &is): Sales_data()
    {
        cout << "Sales_data(istream &is) 执行了" << endl;
        read(is, *this);
    }
    
    
    Sales_data &combine(const Sales_data &rhs);
    string isbn();

    private:
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



int main()
{
    
    Sales_data data1;
    string null_book = "9-999-99999-9";
    unsigned t = 1;
    double t1 = 10.0;
    // data1.combine(null_book);
    data1.combine({null_book, 1, t1});
    return 0;
}
