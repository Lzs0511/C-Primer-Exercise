#include<iostream>
#include<memory>
using namespace std;

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;
    // IntP p0(ix);  //error: no matching function for call to ‘std::unique_ptr<int>::unique_ptr(int&)’
    IntP p1(pi); // 合法， 但是后续可能会出问题
    IntP p2(pi2); // 合法， 但是后续可能会出问题
    IntP p3(&ix); // 能编译， 但是后续会出问题，可能释放栈区数据
    IntP p4(new int(2048)); // 合法
    IntP p5(p2.get()); // 合法，但是后续可能会出问题，p5和p2指向同一个内存，可能会重复释放
    return 0;
}