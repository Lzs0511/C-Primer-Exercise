#include<iostream>
using namespace std;
// void print(const int ia[10])
// {
//     for(size_t i = 0; i != 18; ++i)
//     {
//         cout << ia[i] << endl;
//     }
// }
void print(const int (&ia)[10])
{
    for(size_t i = 0; i != 10; ++i)
    {
        cout << ia[i] << endl;
    }
}
int main()
{
    int a[10];
    for(int i = 0; i < 10; ++i)a[i] = i;
    print(a);
    return 0;
}