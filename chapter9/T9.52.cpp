#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<string> stk;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            stk.push(string(s[i], 1));
        else if(s[i] == ')')
        {
            
        }
    }

    return 0;
}