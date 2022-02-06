#include<iostream>
#include<string>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
    string word;
    list<string> words;
    while(cin >> word)
    {
        words.push_back(word);
    }

    words.sort();
    words.unique();
    for(auto x: words)
    {
        cout << x << endl;
    }
    return 0;
}