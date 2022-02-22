#include"T13.44.h"

#include<iostream>

int main(){
    String s("Hello World");
    std::cout << s << std::endl;
    String s1;
    std::cout << s1 << std::endl;
    s1 = s;
    std::cout << s1 << std::endl;
    s1 = "ssss";
    std::cout << s1 << std::endl;
    String s2(s);
    std::cout << s2 << std::endl;
    return 0;
}