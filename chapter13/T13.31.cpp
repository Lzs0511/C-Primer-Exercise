#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
class HasPtr{
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const std::string &s = std::string(), int _i = 0):ps(new std::string(s)), i(_i), use(new size_t(1)){}
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
    bool operator<(const HasPtr &hp){
        return this->i < hp.i;
    }
    ~HasPtr(){
        if(--*use == 0){
            delete use;
            delete ps;
        }
    }
    int getI(){
        return i;
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

    std::vector<HasPtr> vec;
    for(int i = 100; i != 0; i--){
        HasPtr p("", i);
        vec.push_back(p);
    }
    std::sort(vec.begin(), vec.end());
    for(auto p: vec){
        std::cout << p.getI() << std::endl;
    }
    return 0;
}