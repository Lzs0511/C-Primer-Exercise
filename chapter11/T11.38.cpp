#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    string word;
    unordered_map<string, size_t> word_count;

    while(cin >> word)
    {
        word_count[word]++;
    }
    for(const auto &tmp: word_count)
    {
        cout << tmp.first << "出现的次数为：" << tmp.second << endl;
    }
    return 0;
}