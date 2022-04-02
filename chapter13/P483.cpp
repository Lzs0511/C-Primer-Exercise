#include<iostream>
#include<string>

int main(){
    std::string s1 = "a value", s2 = "another";
    auto n = (s1 + s2).find('a');
    std::cout << n << std::endl;
    return 0;
}
