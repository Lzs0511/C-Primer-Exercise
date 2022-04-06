#ifndef DISC_QUOTE
#define DISC_QUOTE
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

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double sales_price,
                std::size_t qty, double dct):Quote(book, sales_price), quantity(qty), discount(dct){

    }
    virtual double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double sales_price,
                std::size_t qty, double dct):Disc_quote(book, sales_price, qty, dct){}
    virtual double net_price(std::size_t) const override;
};

class Less_quote : public Disc_quote{
public:
    Less_quote() = default;
    Less_quote(const std::string &book, double sales_price, 
                std::size_t qty, double dct):Disc_quote(book, sales_price, qty, dct){}

    virtual double net_price(std::size_t size) const override{
        if(size > quantity)
            return (1 - discount) * price * quantity + (size - quantity) * price;
        return (1 - discount) * quantity * price;
    }
};
#endif