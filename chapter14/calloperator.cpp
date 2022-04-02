#include<iostream>
#include<string>

class MyPrint{
public:
    void operator()(const std::string &s){
        std::cout << s << std::endl;
    }
};

class MyAdd{
public:
    // 函数调用重载也称为“仿函数"
    int operator()(int num1, int num2){
        return num1 + num2;
    }
};
void test01(){
    MyPrint myprint;
    myprint("Hello World");
}

void test02(){
    MyAdd add;
    std::cout << add(100, 200) << std::endl;
    std::cout << MyAdd()(10, 20) << std::endl;

}
int main(){
    test01();
    test02();
    cout << endl; 
}

