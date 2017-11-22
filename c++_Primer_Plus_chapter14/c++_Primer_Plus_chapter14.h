#ifndef C_PRIMER_PLUS_CHAPTER14_H_INCLUDED
#define C_PRIMER_PLUS_CHAPTER14_H_INCLUDED

#include<string>
#include <valarray>

using namespace std;

template <typename T1,typename T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const {return a;}
    T2 second() const {return b;}
    Pair(const T1 &aval,const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

template<typename T1,typename T2>
T1 & Pair<T1,T2>::first()
{
    return a;
}

template<typename T1,typename T2>
T2 & Pair<T1,T2>::second()
{
    return b;
}

template <typename T>
class QueueTp
{
private:
    enum {Q_SIZE = 10};
    struct Node {T item; Node *next;};
    Node *front;
    Node *rear;
    int items;
    const int qsize;
    QueueTp(const QueueTp &q) : qsize(0) {}
    QueueTp & operator=(const QueueTp &q) {return *this;}
public:
    QueueTp(int qs = Q_SIZE);
    ~QueueTp();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T &item);
    bool dequeue(T &item);
};

template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <typename T>
QueueTp<T>::~QueueTp()
{
    Node *temp;
    while(front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
bool QueueTp<T>::isempty() const
{
    return items == 0;
}

template <typename T>
bool QueueTp<T>::isfull() const
{
    return items == qsize;
}

template <typename T>
int QueueTp<T>::queuecount() const
{
    return items;
}

template <typename T>
bool QueueTp<T>::enqueue(const T &item)
{
    if(isfull()) return false;
    Node *add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if(front == nullptr) front = add;
    else rear->next = add;
    rear = add;
    return true;
}

template <typename T>
bool QueueTp<T>::dequeue(T &item)
{
    if(front == nullptr) return false;
    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if(items == 0) rear = nullptr;
    return true;
}

using ArrayInt = valarray<int>;
using PairArray = Pair<ArrayInt,ArrayInt>;

class Wine
{
private:
    string name;
    PairArray data;
    int year_num;
public:
    Wine(const char *l,int y,const int yr[],const int bot[]);
    Wine(const char *l,int y);
    Wine() {}
    void Getbottles();
    const string & Label();
    int Sum();
    void Show();
};

class Wine_pr : private string,private PairArray
{
private:
    int year_num;
public:
    Wine_pr(const char *l,int y,const int yr[],const int bot[]);
    Wine_pr(const char *l,int y);
    Wine_pr() {}
    void Getbottles();
    const string & Label();
    int Sum();
    void Show();
};

class Worker    //abstract base class
{
private:
    string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const string &s,long n) : fullname(s),id(n) {}
    virtual ~Worker();
    virtual void Set() = 0;  //pure virtual function
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(),panache(0) {}
    Waiter(const string & s,long n,int p = 0) : Worker(s,n),panache(0) {}
    Waiter(const Worker & wk,int p = 0) : Worker(wk),panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker
{
protected:
    enum {other,alto,contralto,soprano,bass,baritone,tenor};
   enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    static const char *pv[Vtypes];

    int voice;
public:
    Singer() : Worker(),voice(other) {};
    Singer(const string &s,long n,int v = other) : Worker(s,n),voice(v) {}
    Singer(const Worker &wk,int v = other) : Worker(wk),voice(v) {}
    void Set();
    void Show() const;
};

class SingingWaiter : public Waiter,public Singer
{
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const string &s,long n,int p = 0, int v = other)
            : Worker(s,n),Waiter(s,n,p),Singer(s,n,v) {}
    SingingWaiter(const Worker &wk,int p = 0,int v = other)
            : Worker(wk),Waiter(wk,p),Singer(wk,v) {}
    SingingWaiter(const Waiter &wt,int v = other)
            : Worker(wt),Waiter(wt),Singer(wt,v) {}
    SingingWaiter(const Singer &wt,int p = 0)
            : Worker(wt),Waiter(wt,p),Singer(wt) {}
    void Set();
    void Show() const;
};


#endif // C++_PRIMER_PLUS_CHAPTER14_H_INCLUDED
