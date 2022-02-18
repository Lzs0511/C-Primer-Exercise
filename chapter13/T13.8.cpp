#include<iostream>
#include<memory>
#include<string>

class HasPtr{
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0){}
    HasPtr &operator=(const HasPtr &hp){
        delete(ps);
        this->ps = new std::string(*hp.ps);
        this->i = hp.i;
        return *this;
    }
private:

    std:: string *ps;
    int i;
};