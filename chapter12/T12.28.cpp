#include<iostream>
#include<memory>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<fstream>
#include<sstream>
#include<cstdio>
int main(int argc, char *argv[]){

    // 文件
    std::ifstream infile(argv[1]);
    // 定义数据
    std::map<std::string, std::set<int>> map1;
    std::vector<std::string> content;
    std::set<int> lines;
    std::string line;
    int num = 1;
    while(getline(infile, line)){
        content.push_back(line);
        std::istringstream in(line);
        std::string word;
        while(in >> word){
            map1[word].insert(num);
        }
        num++;
    }
    std::string word;
    while(true){
        std::cout << "请输入您要查找的单词(q退出): ";
        if(!(std::cin >> word) || word == "q")break;
        // 获取 行的集合
        std::set<int> find_set = map1[word];
        std::cout << word << " 出现了 " << find_set.size() << " 次" << std::endl;
        for(auto x : find_set){
            printf("(line %d) %s\n", x, content[x-1].c_str());
        }
    }


    return 0;
}