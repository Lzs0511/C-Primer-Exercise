#include<iostream>
#include<string>
using namespace std;
bool includeUpper(const string &str)
{
    for(auto c : str)
    {
        if(c >= 'A' && c <= 'Z')
        {
            return true;
        }
    }
    return false;
}
void lowerStr(string& str)
{
    for(auto &c : str)
    {
        if(c >= 'A' && c <= 'Z')
        {
            c += 32;
        }
    }
}

int main()
{
    string a = "Hello World";
    cout << (includeUpper(a)? "True" : "False") << endl;
    
    lowerStr(a);
    cout << a << endl;
    return 0;
}