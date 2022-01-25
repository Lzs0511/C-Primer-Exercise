#include<iostream>
#include<string>
using namespace std;

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i)
    {
        if(s[i] == c)
        {
            if(ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
int main()
{
    string::size_type occurs;
    string str = "Hello World!";
    auto index = find_char(str, 'o', occurs);
    cout << index << " " << occurs << endl;
    return 0;
}