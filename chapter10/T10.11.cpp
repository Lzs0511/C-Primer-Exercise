#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isShorter(const string &str1, const string &str2)
{
    return str1.size() < str2.size();
}
int main()
{
    string word;
    vector<string> vec;
    while(cin >> word)vec.push_back(word);
    stable_sort(vec.begin(), vec.end(), isShorter);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(auto str: vec)cout << str << endl;
    return 0;
}