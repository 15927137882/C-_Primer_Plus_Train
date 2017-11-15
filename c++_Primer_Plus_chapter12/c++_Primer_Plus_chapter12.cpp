#include "c++_Primer_Plus_chapter12.h"
#include <cstring>
#include <iostream>
#include <cctype>
#include <cstdlib>

namespace COW
{
    using namespace std;
    Cow::Cow() : hobby(nullptr),weight(0.0)
    {
        name[0] = '\0';
    }

    Cow::Cow(const char *nm,const char *ho,double wt) : weight(wt)
    {
        int len = strlen(nm) > 19 ? 19 : strlen(nm);
        for(int i = 0;i<len;i++) name[i] = nm[i];
        name[len] = '\0';
        len = strlen(ho);
        hobby = new char[len+1];
        strcpy(hobby,ho);
    }

    Cow::Cow(const Cow &c)
    {
        strcpy(name,c.name);
        int len = strlen(c.hobby);
        hobby = new char[len+1];
        strcpy(hobby,c.hobby);
        weight = c.weight;
    }

    Cow::~Cow()
    {
        delete [] hobby;
    }

    Cow & Cow::operator=(const Cow &c)
    {
        if(this == &c) return *this;
        delete [] hobby;
        int len = strlen(c.hobby);
        hobby = new char[len+1];
        strcpy(hobby,c.hobby);
        strcpy(name,c.name);
        weight = c.weight;
        return *this;
    }

    void Cow::ShowCow() const
    {
        cout<<name<<endl;
        cout<<hobby<<endl;
        cout<<weight<<" kg."<<endl;
    }
}

namespace STRING
{
    using std::strlen;
    using std::strcpy;
    using std::strcmp;
    using std::strcat;
    using std::toupper;
    using std::tolower;

    String::String()
    {
        len = 0;
        str = nullptr;
    }

    String::String(const char *s)
    {
        len = strlen(s);
        str = new char[len+1];
        strcpy(str,s);
    }

    String::String(const String &st)
    {
        len = st.len;
        str = new char[len+1];
        strcpy(str,st.str);
    }

    String::~String()
    {
        delete [] str;
    }

    String & String::operator=(const String &st)
    {
        if(this == &st) return *this;
        delete [] str;
        len = st.len;
        str = new char[len+1];
        strcpy(str,st.str);
        return *this;
    }

    String & String::operator=(const char *s)
    {
        delete [] str;
        len = strlen(s);
        str = new char[len+1];
        strcpy(str,s);
        return *this;
    }

    char & String::operator[](int i)
    {
        return str[i];
    }

    const char & String::operator[](int i) const
    {
        return str[i];
    }

    bool operator<(const String &st1,const String &st2)
    {
        return (strcmp(st1.str,st2.str) < 0);
    }

    bool operator>(const String &st1,const String &st2)
    {
        return st2 < st1;
    }

    bool operator==(const String &st1,const String &st2)
    {
        return (strcmp(st1.str,st2.str) == 0);
    }

    ostream & operator<<(ostream &os,const String &st)
    {
        os<<st.str;
        return os;
    }

    istream & operator>>(istream &is,String &st)
    {
        char *p1;
        int size = 10;
        int i = 0;
        char ch;
        ch = is.get();
        p1 = new char[size];
        while(ch != '\n')
        {
            p1[i++] = ch;
            if(i == size)
            {
                char *p2;
                size *= 2;
                p2 = new char[size];
                strcpy(p2,p1);
                delete [] p1;
                p1 = p2;
            }
            ch = is.get();
        }
        p1[i] = '\0';
        st = p1;
        delete [] p1;

        return is;
    }

    String String::operator+(const String &st) const
    {
        int l = len + st.len;
        char *p = new char[l+1];
        strcpy(p,str);
        strcat(p,st.str);
        String temp = p;
        delete [] p;
        return temp;
    }

    void String::Stringlow()
    {
        int i = 0;
        while(str[i] != '\0')
        {
            str[i] = std::tolower(str[i]);
            i++;
        }
    }

    void String::Stringup()
    {
        int i = 0;
        while(str[i] != '\0')
        {
            str[i] = std::toupper(str[i]);
            i++;
        }
    }

    int String::Has(const char ch)
    {
        int count = 0;
        int i = 0;
        while(str[i] != '\0')
        {
            if(str[i] == ch) count++;
            i++;
        }
        return count;
    }

    String operator+(const char* s, String &st)
    {
        String s1(s);
        return s1+st;
    }

}

namespace ATM
{
    using std::rand;

    void Customer::set(long when)
    {
        processtime = rand() % 3 + 1;
        arrive = when;
    }

    Queue::Queue(int qs) : qsize(qs)
    {
        front = rear = nullptr;
        items = 0;
    }

    Queue::~Queue()
    {
        Node *temp;
        while(front != rear)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool Queue::isempty() const
    {
        return items == 0;
    }

    bool Queue::isfull() const
    {
        return items == qsize;
    }

    int Queue::queuecount() const
    {
        return items;
    }

    bool Queue::enque(const Item &item)
    {
        if(isfull()) return false;
        Node * add = new Node;
        add->item = item;
        add->next = nullptr;
        items++;
        if(front == nullptr) front = add;
        else rear->next = add;
        rear = add;
        return true;
    }

    bool Queue::deque(Item &item)
    {
        if(front == nullptr) return false;
        item = front->item;
        items--;
        Node * temp = front;
        front = front->next;
        delete temp;
        if(items == 0) rear = nullptr;
        return true;
    }
}
