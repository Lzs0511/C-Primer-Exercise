#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

map<string, string> buildMap(ifstream &is)
{
    map<string, string> transMap;
    string key, value;
    while(is >> key && getline(is, value))
    {
        if(value.size() > 1)
            transMap[key] = value.substr(1);
        else 
            throw runtime_error("no rule for " + key);
    }
    return transMap;
}
const string &transform(const string &str, map<string, string> &transMap)
{
    // map<string, string>::const_iterator iter = transMap.find(str);
    if(transMap[str] != ""){
        return transMap[str];
    }else{
        return str;   
    }
}
int main(int argc, char *argv[])
{
    ifstream map_in(argv[1]);
    // 构造映射
    auto transMap = buildMap(map_in);
    
    // 处理输入数据
    ifstream input(argv[2]);
    string text;
    while(getline(input, text))
    {
        istringstream in(text);
        string word;
        bool is_first_word = true;
        while(in >> word)
        {
            if(is_first_word)
            {
                cout << transform(word, transMap);
                is_first_word = false;
            }else{
                cout << " " << transform(word, transMap);
            }
        }
        cout << endl;
    }
    return 0;
}