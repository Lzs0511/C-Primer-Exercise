#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, " ");
    vector<int> vec(in, eof);
    // 排序
    sort(vec.begin(), vec.end(), [](const int &n1, const int &n2)->bool{return n1 > n2;});
    // 将输入流中的内容输出到输出流中
    // copy(in, eof, out);
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}