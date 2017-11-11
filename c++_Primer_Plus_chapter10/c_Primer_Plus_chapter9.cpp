#include "c_Primer_Plus_chapter9.h"
#include <string>
#include <iostream>

BankAccount::BankAccount(const string &name,const string &account_num,double balance)
{
    name_ = name;
    account_num_ = account_num;
    balance_ = balance;
}

void BankAccount::Show(void) const
{
    using namespace std;
    cout<<"Name: "<<name_<<endl;
    cout<<"Account number: "<<account_num_<<endl;
    cout<<"Balance: "<<balance_<<endl<<endl;
}

void BankAccount::Deposit(double cash)
{
    balance_ += cash;
}

void BankAccount::Withdraw(double cash)
{
    balance_ -= cash;
}

Person::Person(const string &lname,const char *fname)
{
    lname_ = lname;
    int i = 0;
    while(fname[i] && i <= LIMIT-2)
    {
        fname_[i] = fname[i];
        i++;
    }
    fname_[i] = '\0';
}

void Person::Show() const
{
    using namespace std;
    cout<<fname_<<" "<<lname_<<endl;
}

void Person::FormalShow() const
{
    using namespace std;
    cout<<lname_<<" "<<fname_<<endl;
}

Stack::Stack()
{
    top = 0;
}

bool Stack::IsEmpty() const
{
    return top == 0;
}

bool Stack::IsFull() const
{
    return top == MAX;
}

bool Stack::Push(const Item &item)
{
    if(top<MAX)
    {
        items[top++] = item;
        return true;
    }
    else return false;
}

bool Stack::Pop(Item &item)
{
    if(top>0)
    {
        item = items[--top];
        return true;
    }
    else return false;
}

namespace LIST
{
    bool List::Add(Item item)
    {
        if(tail == MAX) return false;
        else
        {
            items[tail++] = item;
            return true;
        }
    }

    void List::Visit(void (*pf)(Item &))
    {
        for(int i = 0;i<tail;i++)
            (*pf)(items[i]);
    }

}

void show(LIST::Item &item)
{
    using std::cout;
    using std::endl;
    cout<<item<<endl;
}

void add(LIST::Item &item)
{
    using std::cout;
    using std::cin;
    static bool flag = false;
    static LIST::Item n = 0;
    if(!flag)
    {
        cout<<"Add what Number: ";
        cin>>n;
        item += n;
        flag = true;
    }
    else item += n;
}


