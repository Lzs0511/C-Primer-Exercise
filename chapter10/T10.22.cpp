#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool judge(const string &str, string::size_type sz)
{
    return str.size() <= sz;
}
int main()
{
    string word;
    vector<string> words;
    while(cin >> word)words.push_back(word);
    // 使用参数绑定 bind
    auto cnt = count_if(words.begin(), words.end(), bind(judge, _1, 6));
    cout << cnt << endl;
    return 0;
}