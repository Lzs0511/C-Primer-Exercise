#include<iostream>
#include<string>
#include<memory>

class Employee{
public:
    Employee():m_eid(m_num){}
    Employee(const std::string name):m_name(name), m_eid(m_num++){}
    Employee(const Employee &ep) = delete;
    Employee &operator=(const Employee &ep) = delete;
private:
    static int m_num;
    std::string m_name;
    int m_eid;
};
int Employee::m_num = 0;

int main(){
    return 0;
}