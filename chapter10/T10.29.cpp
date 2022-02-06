#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
    ifstream in("T10.29.txt");
    istream_iterator<string> input(in), eof;
    vector<string> vec(input, eof);
    ostream_iterator<string> out(cout, " ");
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}