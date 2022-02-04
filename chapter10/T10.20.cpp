#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string word;
    vector<string> words;
    while(cin >> word)words.push_back(word);

    auto cnt = count_if(words.begin(), words.end(), [](const string &str)->bool{return str.size() > 6;});
    cout << cnt << endl;
    return 0;
}