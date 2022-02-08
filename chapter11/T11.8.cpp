#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> vec;
    string word;
    while(cin >> word)
    {
        if(find(vec.begin(), vec.end(), word) == vec.end())
        {
            vec.push_back(word);
        }
    }
    for(auto str: vec)cout << str << " ";
    cout << endl;
    return 0;
}