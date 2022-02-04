#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
using namespace std;
using namespace std::placeholders;

bool judge(const string &word, string::size_type sz)
{
    return word.size() > sz;
}
int main()
{
    string word;
    vector<string> words;
    while(cin >> word)
    {
        words.push_back(word);
    }

    auto ends = partition(words.begin(), words.end(), bind(judge, _1, 5));
    for_each(words.begin(), ends, [](const string &s){cout << s << " ";});
    cout << endl;
    return 0;
}