#include<iostream>
#include<string>
#include"T15.7.h"

void test(){
    Bulk_quote q1("堂吉诃德", 20, 20, 0.3);
    Quote q2("堂吉诃德", 20);
    print_total(std::cout, q2, 20);
    std::cout << "-------------------" << std::endl;
    print_total(std::cout, q1, 20);
}
void test1(){
    Disc_quote1 q("the old man and the sea", 25, 20, 0.3);
    print_total(std::cout, q, 35);
}
int main(){
    // test();
    test1();
    return 0;
}