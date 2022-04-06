#include<iostream>
#include<string.h>
using namespace std;
class Base{
public:
    Base() = default;
    Base(int a): m_A(a){};
    int m_A;
};

class Derived : public Base{
public:
    Derived() = default;
    Derived(int a):Base(a){this->m_A = 100;};
    int m_A;
};
void test(){
    Base *p = new Derived(10);
    cout << p->m_A << endl;
    p->Base::m_A = 20;
    cout << p->Base::m_A << endl;
    cout << p->m_A << endl;
    p->m_A = 200;
    cout << p->Derived::m_A << endl;
    cout << p->m_A << endl;
}
int main(){

    test();
    return 0;
}