#include<vector>
#include<sstream>
#include<iostream>
using namespace std;
struct record
{
    string name;
    vector<string> phones;
};

int main()
{

    string line;
    vector<record> vec;

    while(getline(cin, line))
    {
        istringstream input(line);
        record rec;
        input >> rec.name;
        string phone;
        while(input >> phone)
        {
            rec.phones.push_back(phone);
        }
        vec.push_back(rec);
    }

    for(auto rec : vec)
    {
        cout << "name: " << rec.name << " phoneNums: " ;
        for(auto phone : rec.phones)
        {
            cout << phone << " ";
        }
        cout << endl;
    }
    return 0;
}