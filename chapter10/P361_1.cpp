#include<vector>
#include<iterator>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");

    vector<int> vec(in, eof);
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}