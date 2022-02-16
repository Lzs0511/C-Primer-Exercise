#include<iostream>
#include<memory>
#include<string>
#include<vector>

int main()
{
    std::allocator<std::string> allo;
    std::string * const p = allo.allocate(10);
    auto q = p;
    allo.construct(q++);
    allo.construct(q++, 10, 'C');
    allo.construct(q++, "Hi");
    // std::cout << *p << std::endl;
    // std::cout << *q << std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << *(p+i) << std::endl;
    }
    return 0;
}