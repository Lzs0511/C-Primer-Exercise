#include<vector>
#include<string>
#include<initializer_list>
#include<exception>
#include<memory>
#include<stdexcept>

using std::vector; using std::string;
using std::initializer_list;
using std::make_shared; using std::shared_ptr;
using std::weak_ptr;
class StrBlobPtr;
class strBlob
{
    friend class StrBlobPtr;
    public:
    typedef vector<string>::size_type size_type;
    // 定义构造函数
    strBlob();
    strBlob(initializer_list<string> l1);
    strBlob(const strBlob &s){
        data = make_shared<vector<string>>(*s.data);
    }
    strBlob &operator=(const strBlob &s){
        data = make_shared<vector<string>>(*s.data);
        return *this;
    }

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

    StrBlobPtr begin();
    StrBlobPtr end();
    private:
    shared_ptr<vector<string>> data;
    void check(size_type size, string msg) const;
};
class StrBlobPtr{
    public:
    bool operator!=(const StrBlobPtr &ptr1){return ptr1.curr != curr;}
    StrBlobPtr():curr(0){};
    StrBlobPtr(strBlob &a, size_t sz = 0):wptr(a.data), curr(sz){ }
    string &deref() const;
    StrBlobPtr& incr();

    private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};
// 定义 StrBlobPtr的中的函数
shared_ptr<vector<string>> StrBlobPtr::check(size_t size, const string &str) const{
    shared_ptr<vector<string>> ret = wptr.lock();
    if(!ret){
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if(size >= ret->size()){
        throw std::out_of_range("out of range");
    }
    return ret;
}

string &StrBlobPtr::deref() const{
    auto ret = check(curr, "deref");
    return (*ret)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    auto ret = check(curr, "incr");
    ++curr;
    return *this;
}
// 定义 strBlob的中的函数
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


StrBlobPtr strBlob::begin(){return StrBlobPtr(*this);}
StrBlobPtr strBlob::end(){
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }