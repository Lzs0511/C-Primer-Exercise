#include<iostream>
#include<string>
#include<vector>
#include<memory>
using namespace std;

shared_ptr<vector<int>> ret_vint()
{
    return make_shared<vector<int>>(10, 10);
}
void input(shared_ptr<vector<int>> vec)
{
    int x;
    while(cin >> x)
    {
        vec->push_back(x);
    }
}

void output(shared_ptr<vector<int>> vec)
{
    for(auto x: *vec)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    auto vec = ret_vint();
    input(vec);
    output(vec);
    cout << vec.use_count() << endl;
    vec = nullptr;
    return 0;
}