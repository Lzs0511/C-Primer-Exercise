#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<const char *> vec{"张三", "李四", "王五", "田七"};
    vector<const char *> vec1{"张三", "李四", "王五", "田七"};

    bool res = equal(vec.cbegin(), vec.cend(), vec1.cbegin());
    cout << res << endl;
    cout << ("张三" == "李四") << endl;
    cout << ("张三" == "张三") << endl;
    return 0;
}