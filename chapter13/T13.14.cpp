#include<iostream>
#include<string>
class numbered;
void f(numbered s);
class numbered{
    friend void f(numbered s);
public:
    numbered():mysn(num++){}
    // numbered(const numbered &n1):mysn(num++){}

private:
    static int num;
    int mysn;
};
int numbered::num = 0;

void f(numbered s){ std::cout << s.mysn << std::endl;}
int main(){
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    return 0;
}