#include<vector>
#include<string>
#include<iostream>

class HasPtr{
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0), use(new size_t(1)){}
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
inline void swap(HasPtr &rhs1, HasPtr &rhs2){
    std::cout << "swap(HasPtr &, HasPtr &) executed...\n" << std::endl;
    using std::swap;
    swap(rhs1.i, rhs2.i);
    swap(rhs1.ps, rhs2.ps);
    swap(rhs1.use, rhs2.use);
}
int main(){

    HasPtr p1, p2;
    swap(p1, p2);
    return 0;
}