#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;


int main(int argc, char *argv[])
{
    vector<string> strs;
    ifstream input(*++argv);
    if(!input)
    {
        cerr << "input open failure !" << endl;
        return 1;
    }
    string s;
    
    while(getline(input, s))
    {
        strs.push_back(s);
    }

    for(auto str: strs)
    {
        string word;
        istringstream in(str);
        while(in >> word)
        {
            cout << word << endl;
        }
    }
    return 0;
}
