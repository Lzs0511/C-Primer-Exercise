#include<iostream>
#include<string>
#include<memory>
using namespace std;

struct destination{

    string ip;
    int port;

    destination()=default;
    destination(string _ip, int _port):ip(_ip), port(_port){};
};

struct connection{
    string ip;
    int port;

    connection()=default;
    connection(string _ip, int _port):ip(_ip), port(_port){};
};

connection connect(destination *dest)
{
    shared_ptr<connection> ptr = make_shared<connection>(dest->ip, dest->port);
    cout << "creating connection (" << ptr.use_count() << ")" << endl;
    return *ptr;
}

void disconnect(connection conn)
{
    cout << "connection close (" << conn.ip << ":" << conn.port << ")" << endl;
}


void f(destination &d)
{
    connection conn = connect(&d);
    shared_ptr<connection> ptr(&conn,[](connection *conn)->void{disconnect(*conn);});
}

int main()
{
    destination dest("192.168.1.1", 80);
    f(dest);
}