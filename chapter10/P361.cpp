#include<iostream>
#include<iterator>
#include<string>
#include<vector>
using namespace std;

int main()
{
    istream_iterator<string> in(cin), eof;
    ostream_iterator<string> out(cout, " ");

    copy(in, eof, out);
    cout << endl;
    return 0;
}