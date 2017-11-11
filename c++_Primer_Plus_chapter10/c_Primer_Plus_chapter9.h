#ifndef C_PRIMER_PLUS_CHAPTER9_H_INCLUDED
#define C_PRIMER_PLUS_CHAPTER9_H_INCLUDED

#include <string>

using std::string;

struct Customer
{
    char fullname[30];
    double payment;
};

class BankAccount
{
private:
    string name_;
    string account_num_;
    double balance_;
public:
    BankAccount(const string &name,const string &account_num,double balance = 0.0);
    void Show(void) const;
    void Deposit(double cash);
    void Withdraw(double cash);
};

class Person
{
private:
    static const int LIMIT = 25;
    string lname_;
    char fname_[LIMIT];
public:
    Person() {lname_ = "";fname_[0] = '\0';}
    Person(const string &lname,const char *fname = "Heyyou");
    void Show() const;
    void FormalShow() const;
};


typedef Customer Item;
class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool IsEmpty() const;
    bool IsFull() const;
    bool Push(const Item &item);
    bool Pop(Item &item);
};

namespace LIST
{
    typedef int Item;
    class List
    {
    private:
        enum {MAX = 10};
        Item items[MAX];
        int tail;
    public:
        List(int n = 0) { tail = n > MAX ? MAX : n;}
        bool Add(Item item);
        bool IsEmpty() {return tail == 0;}
        bool IsFull() {return tail == MAX;}
        void Visit(void (*pf)(Item &));
    };
}

void show(LIST::Item &item);
void add(LIST::Item &item);

#endif // C_PRIMER_PLUS_CHAPTER9_H_INCLUDED
