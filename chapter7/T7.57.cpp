#include<iostream>
#include<string>
using namespace std;

class Account
{
    public:
    void calculate(){ amount += amount * rate;}
    static double getRate();
    static void setRate(double _rate);
    private:
    string owner;
    double amount;
    static double rate;
    static void initRate();
};
void Account::initRate(){ rate = 0.07; }
double Account::rate = initRate();
double Account::getRate()
{
    return rate;
}
void Account::setRate(double _rate)
{
    rate = _rate;
}

