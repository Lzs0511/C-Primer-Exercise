#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    const char *str1 = "Hello,", *str2 = "World!";
    char *str = new char[strlen(str1) + strlen(str2) + 1]();
    strcpy(str, str1);
    strcat(str, str2);

    printf("%s1\n", str);

    string s1 = "Hello,", s2 = "World!";
    size_t size = s1.size() + s2.size() + 1;
    char *buf = new char[size]();
    strcat(buf, s1.c_str());
    strcat(buf, s2.c_str());
    printf("%s\n", buf);
    cout << buf << endl;
    return 0;
}