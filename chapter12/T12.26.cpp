#include<iostream>
#include<memory>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    allocator<string> alloc;
    string *const p = alloc.allocate(n);
    string *q = p;
    string s;
    while(cin >> s && q != p + n){
        alloc.construct(q++, s);
    }
    for(auto i = p; i != q; i++){
        cout << *i << endl;
    }
    const size_t size = q - p;
    alloc.destroy(p);
    alloc.deallocate(p, n);
    return 0;
}