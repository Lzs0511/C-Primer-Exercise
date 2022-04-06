#include<iostream>
#include<string>

struct B{
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : B{
    void f1(int) const override;
    // 以下三行有错误

    /* 
    void f2(int) override; 
    void f3() override;
    void f4() override;
     */
};

struct D2 : B{
    void f1(int) const final;
};
struct D3 : D2{
    void f2();
    // void f1(int) const; // 会出错
};

int main(){

    return 0;
}