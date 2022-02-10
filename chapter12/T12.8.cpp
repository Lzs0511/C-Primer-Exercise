#include<iostream>
using namespace std;
bool b()
{
    int *p = new int;
    return p;

}
int main()
{
    bool ret = b();
    cout << ret << endl;
    
    return 0;
}