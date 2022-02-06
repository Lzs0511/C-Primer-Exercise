#include<iostream>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
    istream_iterator<int> in(cin);
    istream_iterator<int> eof;
    vector<int> vec(in, eof);

    for(int i = 0; i < vec.size(); ++i)cout << vec[i] << endl;
    
    return 0;

}