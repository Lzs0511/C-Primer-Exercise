#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string word;
    vector<string> vec;
    while(cin >> word)vec.push_back(word);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(auto str: vec)cout << str << endl;
    return 0;
}