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
        units_sold(_units_sold), revenue(_revenue * _units_sold)
        { 
            cout << "Sales_data(const string &s, unsigned int _units_sold, double _revenue) 执行了" << endl; 
        } 
    // 委托构造函数 
    Sales_data(): Sales_data("", 0, 0){ cout << "Sales_data() 执行了" << endl;}

    Sales_data(const string &s):Sales_data(s, 0, 0){ cout << "Sales_data(const string &s) 执行了" << endl; }

    Sales_data(istream &is): Sales_data()
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
    
    cout << "测试Sales_data(const string &s, unsigned int _units_sold, double _revenue)" << endl;
    Sales_data data1("123", 1, 2);

    cout << "--------------------------" << endl;
    cout << "测试委托构造函数1" << endl;
    Sales_data data2("456");

    cout << "--------------------------" << endl;
    cout << "测试委托构造函数2" << endl;
    Sales_data data3;

    cout << "--------------------------" << endl;
    cout << "测试委托构造函数3" << endl;
    Sales_data data4(cin);
}
