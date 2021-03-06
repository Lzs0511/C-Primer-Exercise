#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include<iostream>
#include<string>

class Quote{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
                                            bookNo(book), price(sales_price){}
    std::string isbn() const{return bookNo; }
    virtual double net_price(std::size_t n)const {
        return n * price;
    }

    virtual ~Quote() = default;
    virtual void debug(){
        std::cout << "Class Quote:" << std::endl;
        std::cout << "---- private:" << std::endl;
        std::cout << "-------- std::string bookNo" << std::endl;
        std::cout << "---- protected:" << std::endl;
        std::cout << "-------- double price" << std::endl;
    }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote1 : public Quote{
public:
    Disc_quote1() = default;
    Disc_quote1(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override;
    virtual void debug(){
        std::cout << "Class Disc_quote:" << std::endl;
        std::cout << "---- private:" << std::endl;
        // std::cout << "-------- std::string bookNo" << std::endl;
        std::cout << "-------- std::size_t min_qty" << std::endl;
        std::cout << "-------- double discount" << std::endl;
        std::cout << "---- protected:" << std::endl;
        std::cout << "-------- double price" << std::endl;
    }
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double , std::size_t, double);
    double net_price(std::size_t) const override;
    virtual void debug() override{
        std::cout << "Class Bulk_quote:" << std::endl;
        std::cout << "---- private:" << std::endl;
        // std::cout << "-------- std::string bookNo" << std::endl;
        std::cout << "-------- std::size_t min_qty" << std::endl;
        std::cout << "-------- double discount" << std::endl;
        std::cout << "---- protected:" << std::endl;
        std::cout << "-------- double price" << std::endl;
    }
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};
Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
                        Quote(book, p), min_qty(qty), discount(disc){ }

double Bulk_quote::net_price(std::size_t cnt) const{
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

Disc_quote1::Disc_quote1(const std::string &book, double p, std::size_t qty, double disc):
                            Quote(book, p), min_qty(qty), discount(disc){ }
double Disc_quote1::net_price(std::size_t cnt) const {
    if(min_qty >= cnt)
        return price * (1 - discount) * cnt;
    else
        return price * (1 - discount) * min_qty + price * (cnt - min_qty);
}
double print_total(std::ostream &os, const Quote &item, std::size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret; 
}



#endif