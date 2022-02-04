#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
using namespace std::placeholders;
void sort_unique(vector<string> &vec)
{
    sort(vec.begin(), vec.end());
    unique(vec.begin(), vec.end());
}
// 定义函数作为partition的一元谓词
bool check_size(const string &str, string::size_type sz)
{
    return str.size() > sz;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    // 字典序加去重
    // sort_unique(words);
    // 按字符大小排序
    // stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    // 找到第一个字符串长度大于等于sz的字符串
    // 使用bind 绑定 check_size;
    auto check5 = bind(check_size, _1, sz);
    // auto wc = partition(words.begin(), words.end(), [sz](const string s)->bool{return s.size() > sz;});
    auto wc = partition(words.begin(), words.end(), check5);


    for_each(words.begin(), wc, [](const string &s)->void{cout << s << " ";});
    cout << endl;
    return;
}

int main()
{

    vector<string> vec;
    string word;
    while(cin >> word)
    {
        vec.push_back(word);
    }
    biggies(vec, 5);
    return 0;
}