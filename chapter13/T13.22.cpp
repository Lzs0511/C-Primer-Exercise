#include<iostream>
#include<string>

class HasPtr{
public:
    HasPtr(const std::string &s):ps(new std::string(s)), i(0){}
    HasPtr(const HasPtr &hp):ps(new std::string(*hp.ps)), i(hp.i){}
    HasPtr &operator=(const HasPtr &hp){
        auto new_ps = new std::string(*hp.ps);
        delete ps;
        this->ps = new_ps;
        this->i = hp.i;
        return *this;
    }
    ~HasPtr(){
        delete ps;
    }
private:
    std::string *ps;
    int i;
};

int main(){
    return 0;
}