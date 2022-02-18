#include<iostream>
#include<memory>
#include<string>

class HasPtr{
public:
    HasPtr(const std::string &s):ps(new std::string(s)), i(0){}

    ~HasPtr(){
        delete ps;
    }

private:
    std::string *ps;
    int i;
};