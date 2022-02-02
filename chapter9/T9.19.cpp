#include<iostream>
#include<string>
#include<list>
using namespace std;
list<string> l1;
void printList(list<string>::const_iterator st, list<string>::const_iterator end)
{
    while(st != end)
    {
        cout << *st++ << endl;
    }
}

int main()
{
    string word;
    while(cin >> word)
    {
        l1.push_back(word);
    }
    printList(l1.begin(), l1.end());
    return 0;
}