#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Foo{
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    std::vector<int> data;
};

Foo Foo::sorted() &&{
    std::cout << "&& sorted execute..." << std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}
// 无限递归，直到栈溢出
/*
Foo Foo::sorted() const & {
    Foo ret(*this);
    //std::sort(ret.data.begin(), ret.data.end());
    std::cout << "const sorted execute..." << std::endl;
    return ret.sorted();
}
*/
// 调用右值引用的sorted版本，能够正常运行
Foo Foo::sorted() const & {
    return Foo(*this).sorted();
}
int main(){
    Foo ret;
    ret.sorted();
    return 0;
}

