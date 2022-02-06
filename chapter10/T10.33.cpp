#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<iterator>
using namespace std;
int main(int argc, char *argv[])
{
    ifstream input(argv[1]);

    ofstream output1(argv[2]), output2(argv[3]);

    istream_iterator<int> in(input), eof;
    ostream_iterator<int> out1(output1, " "), out2(output2, "\n");
    vector<int> v1, v2;
    // 偶数
    // auto iter = partition(in, eof, [](const int &n)->bool{return n % 2 == 0;}); // 不能用
    for_each(in, eof, [&](const int &n){if(n % 2) v1.push_back(n); else v2.push_back(n);} );
    copy(v1.begin(), v1.end(), out1);
    // iter = partition(in, eof, [](const int &n)->bool{return n % 2 == 1;}); 不能用
    copy(v2.begin(), v2.end(), out2);


    return 0;
}
