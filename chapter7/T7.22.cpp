#include<iostream>
#include<string>
using namespace std;

class Person
{
    public:
    // 构造函数
    Person() = default;
    Person(const string& _name, const string& _address):name(_name), address(_address){}
    const string & getName() const ;
    string getAddress() const;
    void setName(string name);

    privae:
    string name;
    string address;
    
};
const string &Person::getName() const
{
    return this->name;
}
string Person::getAddress() const
{
    return this->address;
}
void Person::setName(string name)
{
    this->name = name;
}
int main()
{
    Person p1;
    p1.setName("张三");

    cout << p1.getName() << endl;
    return 0;
}