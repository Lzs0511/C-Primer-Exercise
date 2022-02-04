#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n = 20;
    auto f = [n]()mutable{
        while(n){
            cout << n << endl;
            n--;
        } 
        return !n;
    };
    
    cout << f() << endl;
    cout << "------" << endl;
    cout << f() << endl;

    
}