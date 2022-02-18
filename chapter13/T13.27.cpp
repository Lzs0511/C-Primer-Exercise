#include<iostream>
#include<string>

class HasPtr{
public:
    HasPtr(const std::string &s):ps(new std::string(s)), i(0), use(new size_t(1)){}
    HasPtr(const HasPtr &hp):ps(hp.ps), i(hp.i), use(hp.use){++*use;}
    HasPtr &operator=(const HasPtr &hp){
        // 递增右侧对象的引用计数
        ++*hp.use;
        if(--*use == 0){
            delete ps;
            delete use;
        }
        ps = hp.ps;
        use = hp.use;
        i = hp.i;
        return *this;
    }
    ~HasPtr(){
        if(--*use == 0){
            delete use;
            delete ps;
        }
    }
private:
    std::string *ps;
    size_t *use;
    int i;
};

int main(){
    return 0;
}