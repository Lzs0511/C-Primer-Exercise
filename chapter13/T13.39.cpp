#include"T13.39.h"
#include<iostream>
#include<string>
#include<cstdlib>

void test(StrVec &vec){
    for(auto begin = vec.begin(); begin != vec.end(); begin++) std::cout << *begin << std::endl;
    std::cout << vec.capacity() << std::endl;
    std::cout << vec.size() << std::endl;
}
int main(){
    
    StrVec vec;
    for(size_t i = 0; i < 10; i++){
        // std::string s = "Hello World";
        std::string s = "Hello World";
        s += std::to_string(i);
        std::cout << s << std::endl;
        vec.push_back(s);
    }
    std::cout << "-----------------------" << std::endl;
    test(vec);
    std::cout << "after resize()" << std::endl;
    vec.resize(5);
    test(vec);

    std::cout << "second resize()" << std::endl;
    vec.resize(100);
    test(vec);
    vec.push_back("ss");
    test(vec);
    vec.push_back("ss");
    test(vec);
    vec.reserve(300);
    test(vec);
    return 0;
}