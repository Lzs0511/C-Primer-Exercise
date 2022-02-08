#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string word;
    map<string, size_t> word_count;

    while(cin >> word)
    {
        std::pair<std::map<string, size_t>::iterator, bool> ret = word_count.insert(map<string, int>::value_type(word, 1));
        if(!ret.second){
            ret.first->second++;
        }
    }
    

    for(auto word_cnt: word_count)
    {
        cout << word_cnt.first << "出现了: " << word_cnt.second << endl; 
    }
    return 0;
}