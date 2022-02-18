#include<iostream>
#include<string>
#include<memory>

class X{
public:
    X(){std:: cout << "X()" << std::endl;}
    X(const X &x1){std::cout << "X(const X &x1)" << std::endl;}
    X &operator=(const X &x1){
        std::cout << "X &operator=(const X &x1)" << std::endl;
        this->i = x1.i;
        this->j = x1.j;
        return *this;
    }
private:
    int i;
    int j;
};
void func1(const X &x1){
    std::cout << "func1" << std::endl;
}
void func2(X x1){
    std::cout << "func2" << std::endl;
}
X func3(X x1){
    std::cout << "func3" << std::endl;
    return x1;
}
X &func4(X &x1){
    std::cout << "func4" << std::endl;
    return x1;
}
int main(){
    X x1;
    // X x2 = x1;
    // X x3(x1);
    // x2 = x1;
    // func1(x1);
    // func2(x1);
    // func3(x1);
    func4(x1);
    return 0;
}