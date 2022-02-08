#include<iostream>
#include<vector>
using namespace std;

int main()
{
    using PSI = pair<string, int>;

    string s1;
    int n;
    PSI p1;
    vector<PSI> vec;
    while(cin >> p1.first >> p1.second)
    {
        vec.push_back(p1);
    }
    for(auto pi: vec)
    {
        cout << "first:" << pi.first << ", second:" << pi.second << endl;
    }
    return 0;

}