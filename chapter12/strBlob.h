#include<vector>
#include<string>
#include<initializer_list>
#include<exception>
#include<memory>

using std::vector; using std::string;
using std::initializer_list;
using std::make_shared; using std::shared_ptr;
class strBlob
{
    public:
    typedef vector<string>::size_type size_type;
    // 定义构造函数
    strBlob();
    strBlob(initializer_list<string> l1);

    // 定义对data的操作
    // 添加操作
    void push_back(const string &str){data->push_back(str);};
    // 删除操作
    void pop_back();
    // 获取最后一个元素
    const string &back() const;
    string &back();
    // 获取第一个元素
    string &front();
    const string &front() const;
    private:
    shared_ptr<vector<string>> data;
    void check(size_type size, string msg) const;
};

// 定义构造函数
strBlob::strBlob():data(make_shared<vector<string>>()){};
strBlob::strBlob(initializer_list<string> l1):data(make_shared<vector<string>>(l1)){};

// 定义操作
const string &strBlob::back() const 
{
    check(0, "out of range");
    return data->back();
}
string &strBlob::back()
{
    check(0, "out of range");
    return data->back();
}

const string &strBlob::front() const
{
    check(0, "out of range");
    return data->front();
}
string &strBlob::front()
{
    check(0, "out of range");
    return data->front();
}

void strBlob::pop_back()
{
    check(0, "out of range");
    data->pop_back();
}
void strBlob::check(size_type size, string msg) const
{
    if(data->size() < size)
    {
        throw std::out_of_range(msg);
    }
}