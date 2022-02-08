#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

int main()
{
    string word;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                            "the", "but", "and", "or", "an", "a", ".", "、", ","};
    map<string, size_t> word_cnt;
    while(cin >> word)
    {
        if(exclude.find(word) == exclude.end())
        {
            ++word_cnt[word];
        }
    }

    for(auto x: word_cnt)
    {
        cout << x.first << " size is " << x.second << endl;
    }
    return 0;
}