#include<iostream>
#include<string>
#include<memory>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0){}

    // 拷贝构造函数
    HasPtr(const HasPtr &other):ps(new std::string(*other.ps)), i(other.i){}
private:
    std::string *ps;
    int i;
}