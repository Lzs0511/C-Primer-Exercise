#include<iostream>
#include<string>
#include"T15.5.h"

void test(){
    Bulk_quote q1("堂吉诃德", 20, 20, 0.3);
    Quote q2("堂吉诃德", 20);
    print_total(std::cout, q2, 20);
    std::cout << "-------------------" << std::endl;
    print_total(std::cout, q1, 20);
}
int main(){
    test();
    return 0;
}