#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool isTrue(const string &str)
{
    return str.size() >= 5;
}
int main()
{
    string word;
    vector<string> vec;
    while(cin >> word)
    {
        vec.push_back(word);
    }
    cout << "-----------------" << endl;
    auto partition_end = partition(vec.begin(), vec.end(), isTrue);
    auto curr = vec.begin();
    while(curr != partition_end)
    {
        cout << *curr << endl;
        ++curr;
    }
    return 0;
}