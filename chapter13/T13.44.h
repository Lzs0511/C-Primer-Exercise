#ifndef STRING_H
#define STRING_H
#include<cstring>
#include<memory>
#include<algorithm>
#include<iostream>
class String{
    friend std::ostream &operator<<(std::ostream &os, const String &s);
public:
    // 构造函数
    String():elements(){
        copy("");
    }
    String(const char *str);
    // 拷贝构造函数
    String(const String &str);
    // 析构函数
    ~String(){
        free();
    }
    // 拷贝赋值运算符
    String &operator=(const String &str);
    String &operator=(const char *str);
    // std::ostream &operator<<(std::ostream &os, const String &s);

private:
    static std::allocator<char> alloc;
    // 定义data来存放数据
    char *elements;
    void free(); // 释放资源
    void copy(const char *s);
};
void String::copy(const char *str){
    int num = strlen(str) + 1;
    elements = alloc.allocate(num);
    for(auto beg = elements; *str; str++,beg++){
        // std::cout << *str << std::endl;
        alloc.construct(beg, *str);
    }
    alloc.construct(elements + num - 1, '\0');
}
String::String(const char *str){
    std::cout << "String(const char *str)" << std::endl;
    copy(str);
}
// 拷贝构造函数
String::String(const String &s){
    std::cout << "String(const String &s)" << std::endl;
    auto newdata = s.elements;
    copy(newdata);
}
String &String::operator=(const String &s){
    std::cout << "String &operator=(const String &s)" << std::endl;
    auto newdata = s.elements;
    free();
    copy(newdata);
    return *this;
}

String &String::operator=(const char *s){
    auto newdata = s;
    free();
    copy(newdata);
    return *this;
}

void String::free(){
    if(elements){
        int num = strlen(elements);
        std::for_each(elements, elements+num, [](char &s){alloc.destroy(&s);});
        alloc.deallocate(elements, num+1);
    }
}
std::ostream &operator<<(std::ostream &os, const String &s){
    os << s.elements;
    return os;
}
std::allocator<char> String::alloc;
#endif