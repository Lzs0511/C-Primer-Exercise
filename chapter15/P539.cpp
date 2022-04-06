#include<iostream>
using namespace std;

class Base{
public:
    Base(){
        cout << "Base的构造函数调用了..." << endl;
    }
    virtual void func1(int a = 10, int b = 20){
        cout << "base::func1调用了..." << endl;
        cout << "a: " << a << " b: " << b << endl;
    }
};

class Son : public Base{
public:
    Son(){
        cout << "Son的构造函数调用了..." << endl;
    }
    void func1(int a = 5, int b = 10){
        cout << "son::func1调用了..." << endl;
        cout << "a: " << a << " b: " << b << endl;
    }
};

void test(){
    Base *base = new Son();
    base->func1();
}
int main(){
    test();
    return 0;
}