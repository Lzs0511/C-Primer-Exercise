#include<string>
#include<iostream>
using namespace std;

bool str_subrange(const string &str1, const string &str2){
    
    if(str1.size() == str2.size()) return str1 == str2;

    auto size = (str1.size() < str2.size()? str1.size() : str2.size());

    for(decltype(size) i = 0; i != size; ++i){
        if(str1[i] != str2[i])
        return 1;
    }
    // 末尾没有返回语句，g++ 只警告了，但是并没有编译出错
}
int main()
{
    cout << str_subrange("Hello World", "hello world") << endl;
    return 0;
}