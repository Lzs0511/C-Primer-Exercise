#include<iostream>
#include "T12.19.h"
#include<fstream>

using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    string line;
    strBlob blob;
    while(getline(input, line))
    {
        blob.push_back(line);
    }

    StrBlobPtr blobptr(blob);
    
    for(StrBlobPtr ptr = blob.begin(); ptr != blob.end(); ptr.incr())
    {
        cout << ptr.deref() << endl;
    }
    return 0;
}