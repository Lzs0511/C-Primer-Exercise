#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<fstream>
#include<sstream>
#include"T12.19.h"
class QueryResult;
void print(std::ostream &os, const QueryResult &res);
class TextQuery{
public:
    using size = std::vector<std::string>::size_type;
    TextQuery() = default;
    TextQuery(std::ifstream & in);
    QueryResult query(const std::string &str);

private:
    strBlob file;
    std::map<std::string, std::shared_ptr<std::set<size>>> wm;
};

TextQuery::TextQuery(std::ifstream & in) {
    int num = 0;
    std::string text;
    while(getline(in, text)){
        std::istringstream input(text);
        file.push_back(text);
        std::string word;
        while(input >> word){
            auto &line = wm[word];
            if(!line) line.reset(new std::set<size>);
            line->insert(num);
        }
        num++;
    }
}

class QueryResult{
    friend void print(std::ostream &os, const QueryResult &res);
public:
    QueryResult(strBlob f, 
                std::shared_ptr<std::set<TextQuery::size>> l, std::string w):
                lines(f), line_no(l), word(w){}
private:

    // 存放内容的content
    strBlob lines;
    std::shared_ptr<std::set<TextQuery::size>> line_no;
    std::string word;
};

QueryResult TextQuery::query(const std::string &str){
    static std::shared_ptr<std::set<size>> nodata(new std::set<size>);
    auto ret = wm.find(str);
    if(ret == wm.end()){
        return QueryResult(file, nodata, str);
    }else{
        return QueryResult(file, ret->second, str);
    }
}

void print(std::ostream &os, const QueryResult &res){

    os << res.word << " occurs " << res.line_no->size() << (res.line_no->size() > 1 ? " times" : "time") << std::endl;
    for(auto tmp : *res.line_no){
        os << "(line " << (tmp + 1) << ")" << *(res.lines->begin() + tmp) << std::endl;
    }
}

void runTextQuery(std::ifstream &infile){
    TextQuery tq(infile);
    // 用户输入数据
    while(true){
        std::string s;
        if(!(std::cin >> s) || s == "q")break;
        print(std::cout, tq.query(s));
    }
}
int main(int argc, char *argv[]){

    if(argc < 2){
        std::cout << "format: command filename" << std::endl;
    }
    std::ifstream infile(argv[1]);
    runTextQuery(infile);
    return 0;
}