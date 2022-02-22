#ifndef STRVEC_H
#define STRVEC_H
#include<string>
#include<iostream>
#include<utility>
#include<algorithm>
#include<memory>
class StrVec{
public:
    using PSS = std::pair<std::string *, std::string*>;
    StrVec():elements(nullptr),first_free(nullptr), cap(nullptr){}
    StrVec(std::initializer_list<std::string> list):elements(nullptr),first_free(nullptr), cap(nullptr){
        for(auto i = list.begin(); i != list.end(); ++i){
            this->push_back(*i);
        }
    }
    // 析构函数
    ~StrVec(){ free(); }
    // 拷贝构造函数
    StrVec(const StrVec &s);
    // 拷贝赋值函数
    StrVec &operator=(const StrVec &s);
    // size函数
    size_t size() const { return this->first_free - this->elements; }
    // capacity 函数
    size_t capacity() const{ return this->cap - this->elements; }
    // reserve 函数
    void reserve(size_t reverse_size);
    // resize 函数
    void resize(size_t resize_size);
    // push_back函数
    void push_back(const std::string &s);
    std::string *begin(){ return elements; }
    std::string *end(){ return first_free; }

private:

    std::string *elements;
    std::string *first_free;
    std::string *cap;
    static std::allocator<std::string> alloc; // 分配元素
    PSS allo_n_copy(const std::string *b, const std::string *e);
    void chk_n_alloc(){
        if(size() == capacity())reallocate();
    }
    void reallocate(size_t newcapacity = 0);
    void free();
};

void StrVec::push_back(const std::string &s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

StrVec::PSS StrVec::allo_n_copy(const std::string *b, const std::string *e){
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free(){
    if(elements){
        std::for_each(elements, first_free, [](std::string rhs)->void{alloc.destroy(&rhs);});
        alloc.deallocate(elements, capacity());
    }
}
void StrVec::reallocate(size_t newcapacity){
    // 确定新分配内存空间的大小
    // auto newcapacity = size()? size() * 2: 1;
    if(newcapacity == 0)newcapacity = size()? size() * 2: 1;
    auto newdata = alloc.allocate(newcapacity);

    // 将旧元素移动到新分配的内存空间中
    auto dest = newdata;
    auto elem = elements;
    while(elem != first_free){
        alloc.construct(dest++, std::move(*elem++));
    }
    // 释放旧的内存空间
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

StrVec::StrVec(const StrVec &s){
    auto newdata = allo_n_copy(s.elements, s.first_free);
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &s){
    auto newdata = allo_n_copy(s.elements, s.first_free);
    free();
    elements = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
    return *this;
}

void StrVec::reserve(size_t reserve_size){
    if(reserve_size <= size())return ;
    reallocate(reserve_size);
}

void StrVec::resize(size_t resize_size){
    if(resize_size < size()){
        while(first_free != elements + resize_size){
            alloc.destroy(--first_free);
        }
    }else if(resize_size <= capacity()){
        while(first_free != cap){
            alloc.construct(first_free++);
        }
    }else if(resize_size > capacity()){
        reallocate(resize_size);
        while(first_free != cap){
            alloc.construct(first_free++);
        }
    }
}
std::allocator<std::string> StrVec::alloc;

#endif