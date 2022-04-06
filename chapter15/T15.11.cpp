#include<iostream>
#include<string>
#include"T15.7.h"
void test(){
    Quote *q = new Disc_quote1();
    q->debug();
}
int main(){
    test();
    return 0;
}