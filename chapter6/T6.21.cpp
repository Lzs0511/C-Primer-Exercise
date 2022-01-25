#include<iostream>
using namespace std;
int max(int, const int *);
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int maxNum = max(n1, &n2);
    cout << maxNum << endl;

    return 0;
}
int max(int n1, const int *n2)
{
    return (n1 > *n2)? n1 : *n2;
    
}