#include<list>
#include<iostream>
#include<string>
#include<iterator>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

int main()
{
    srand(time(NULL));
    list<int> l1;
    for(int i = 0; i != 100; i++)l1.push_back(rand()%10);

    list<int>::const_reverse_iterator iter = find(l1.crbegin(), l1.crend(), 0);

    // auto iter = find(l1.crbegin(), l1.crend(), 0);


    cout << *iter << endl;
}