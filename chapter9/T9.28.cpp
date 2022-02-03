#include<iostream>
#include<forward_list>
#include<string>
using namespace std;

// void insert_str(forward_list<string> &l1, string s1, string s2)
// {
//     auto curr = l1.begin();
//     auto prev = l1.before_begin();
//     while(curr != l1.end() && *curr != s1)
//     {
//         prev = curr;
//         ++curr;
//     }
//     if(curr != l1.end()) l1.insert_after(curr, s2);
//     else l1.insert_after(prev, s2);

// }
void insert_str(forward_list<string> &l1, const string &s1, const string &s2)
{
    auto curr = l1.begin();
    auto prev = l1.before_begin();
    while(curr != l1.end())
    {
        if(*curr == s1)
        {
            l1.insert_after(curr, s2);
            return;
        }
        prev = curr;
        ++curr;
    }
    l1.insert_after(prev, s2);
}
int main()
{
    forward_list<string> strlist{"Hello World", "H1", "H2", "h3", "Hello C++"};

    insert_str(strlist, "Hello World", "insert1");
    insert_str(strlist, "张三", "insert2");
    for(auto str: strlist)
    {
        cout << str << endl;
    }
    return 0;
}