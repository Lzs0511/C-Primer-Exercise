#include<iostream>
#include<memory>
#include<string>
#include<vector>
using namespace std;

vector<int> *ret_vint()
{
    return new vector<int>;
}

void input(vector<int> *vec)
{
    int x;
    while(cin >> x)
    {
        vec->push_back(x);
    }
}
void output(vector<int> *vec)
{
    for(const auto x: *vec)
    {
        cout << x << ' ';
    }

    cout << endl;
}
int main()
{
    vector<int> *vec = ret_vint();
    input(vec);
    output(vec);
    delete vec;
    return 0;
}