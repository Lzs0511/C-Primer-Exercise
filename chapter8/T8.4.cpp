#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    vector<string> vec;
    string word;
    for(auto i = argv+1; i != argv + argc; i++)
    {
        // string s;
        ifstream input(*i);
        // getline(input);
        // input >> s;
        while(input >> s)
        {
            // if(s == " ")
            // {
            //     cout << word << endl;
            //     vec.push_back(word);
            //     continue;
            // }
            // word += s;
            // cout << s << endl;
            vec.push_back(s);
        }
            
    }
    // cout << "------------------" << endl;
    for(auto s: vec)
    {
        cout << s << endl;
    }
    return 0;
}