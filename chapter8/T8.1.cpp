#include<iostream>
#include<string>
using namespace std;
istream &readChar(istream &is)
{
    string s;
    istream::iostate state  = is.rdstate();
    while(is >> s)
    {
        cout << s << endl;
    }
    cout << "eof:" << is.eof() << endl;
    is.setstate(state);
    return is;
}
int main()
{
    readChar(cin);
    return 0;
}