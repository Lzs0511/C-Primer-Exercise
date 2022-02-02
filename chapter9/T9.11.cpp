#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> c; // 创建一个空的容器

    vector<int> c1(c); // 使用c的副本构造一个容器
    vector<int> c2 = c; //同上

    vector<int> c3 = {1, 2, 3, 4, 5}; // 构造了一个容器，容器中包含5个元素， 这些元素分别是1，2，3，4，5
    vector<int> c4{1, 2, 3, 4, 5}; // 同上

    vector<int> c5(c3.begin(), c3.end()); // 使用c3的迭代器构造一个容器
    
    vector<int> c6(10); //构造一个具有10个元素容器，该元素值都为0
    vector<int> c7(10, 3); // 构造一个具有10个元素的容器，元素值都为3
    
}