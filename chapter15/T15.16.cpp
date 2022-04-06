#include<iostream>
#include<string>
#include"T15.15.h"

void test(){
    Disc_quote *q1 = new Less_quote("The old man and the sea", 20, 15, 0.3);
    double ret = q1->net_price(100);
    std::cout << "total price is " << ret << std::endl;
}
int main(){
    test();
    return 0;
}