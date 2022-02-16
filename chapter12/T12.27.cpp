#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
class QueryResult{

    public:
    const vector<string> &getcontent(){
        return content;
    }
    void setcontent(const vector<string> &con){
        copy(con.begin(), con.end(), back_inserter(content));
    }
    void setcontent(const string &con){
        content.push_back(con);
    }
    const set<int> &getline(){
        return lines;
    }
    void setlines(const set<int> &_lines){
        copy(_lines.begin(), _lines.end(), inserter(lines, lines.begin()));
    }
    const string &getword(){
        return word;
    }
    void setword(const string &_word){
        word = _word;
    }
    private:
    // 存放内容和行数
    vector<string> content;
    set<int> lines;
    string word;
};
class TextQuery{
    
    public:
    TextQuery(ifstream &infile){
        string words;
        string word;
        int num = 1;
        while(getline(infile, words)){
            text.push_back(words);
            istringstream in(words);
            while(in >> word){
                // 取出单词
                ctol[word].insert(num);
            }
            num++;
        }
    }
    shared_ptr<QueryResult> query(const string &s){
        shared_ptr<QueryResult> ptr = make_shared<QueryResult>();
        // 遍历map 将内容存到vector中
        ptr->setword(s);
        ptr->setlines(ctol[s]);
        for(auto x : ctol[s]){
            ptr->setcontent(text[x-1]);
        }
        return ptr;
    }

    private:
    vector<string> text;
    map<string, set<int>> ctol;
    set<int> lines;
};

void print(ostream &os, shared_ptr<QueryResult> ptr){
    cout << ptr->getword() << " occurs " << ptr->getline().size() << " times" << endl;
    auto vec = ptr->getcontent();
    for(auto tmp: ptr->getline()){
        cout << "(line " << tmp << ") " << ptr->getcontent()[tmp-1] << endl;
    }
}

void runTextQuery(ifstream &infile){
    TextQuery tq(infile);
    // 用户输入数据
    while(true){
        string s;
        if(!(cin >> s) || s == "q")break;
        print(cout, tq.query(s));
    }
}
int main(int argc, char **argv){
    ifstream input(argv[1]);

    runTextQuery(input);

    return 0;
}