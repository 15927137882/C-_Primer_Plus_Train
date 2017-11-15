#ifndef C_PRIMER_PLUS_CHAPTER12_H_INCLUDED
#define C_PRIMER_PLUS_CHAPTER12_H_INCLUDED
#include <iostream>

namespace COW
{
    class Cow
    {
    private:
        char name[20];
        char *hobby;
        double weight;
    public:
        Cow();
        Cow(const char *nm,const char *ho,double wt);
        Cow(const Cow &c);
        ~Cow();
        Cow & operator=(const Cow &c);
        void ShowCow() const;
    };
}

namespace STRING
{

    using std::ostream;
    using std::istream;

    class String
    {
    private:
        char *str;
        int len;
    public:
        String(const char *s);
        String();
        String(const String &st);
        ~String();
        int length() const {return len;}

        String & operator=(const String &st);
        String & operator=(const char *s);
        char & operator[](int i);
        const char & operator[](int i) const;
        String operator+(const String &st) const;


        friend bool operator<(const String &st1,const String &st2);
        friend bool operator>(const String &st1,const String &st2);
        friend bool operator==(const String &st1,const String &st2);
        friend ostream & operator<<(ostream &os,const String &st);
        friend istream & operator>>(istream &is,String &st);
        friend String operator+(const char* s, String &st);

        void Stringlow();
        void Stringup();
        int Has(const char ch);
    };
}

namespace ATM
{
    class Customer
    {
    private:
        long arrive;
        int processtime;
    public:
        Customer() : arrive(0),processtime(0) {}
        void set(long when);
        long when() const {return arrive;}
        int ptime() const {return processtime;}
    };

    typedef Customer Item;

    class Queue
    {
    private:
        struct Node {Item item;struct Node *next;};
        enum {Q_SIZE = 10};
        Node *front;
        Node *rear;
        int items;
        const int qsize;
        Queue(const Queue &q) : qsize(0) {}
        Queue & operator=(const Queue &q) {return *this;}
    public:
        Queue(int qs = Q_SIZE);
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enque(const Item &item);
        bool deque(Item &item);
    };
}

#endif // C++_PRIMER_PLUS_CHAPTER12_H_INCLUDED
