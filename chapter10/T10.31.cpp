#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");
    vector<int> v1;
    copy(in, eof, back_inserter(v1));
    sort(v1.begin(), v1.end());
    unique_copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}