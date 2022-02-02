#include<iostream>
#include<deque>
#include<string>
using namespace std;
deque<string> d1;
void printDeque(deque<string>::const_iterator st, deque<string>::const_iterator end)
{
    while(st != end)
    {
        cout << *st++ << endl;
    }
    // return 0;
}

int main()
{
    string word;
    while(cin >> word)
    {
        d1.push_back(word);   
    }
    printDeque(d1.begin(), d1.end());
    return 0;
}