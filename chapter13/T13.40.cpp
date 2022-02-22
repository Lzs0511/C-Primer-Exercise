#include"T13.43.h"
void test(StrVec &vec){
    for(auto begin = vec.begin(); begin != vec.end(); begin++) std::cout << *begin << std::endl;
    std::cout << vec.capacity() << std::endl;
    std::cout << vec.size() << std::endl;
}
int main(){
    StrVec vec({"H1", "H2", "H3"});
    test(vec);

    return 0;
}