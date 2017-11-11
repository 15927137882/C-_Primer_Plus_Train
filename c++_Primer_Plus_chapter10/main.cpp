#include "c_Primer_Plus_chapter9.h"
#include <iostream>
#include <string>



using namespace std;

int main()
{
    /*
    //10-1
    BankAccount account_list[3] =
    {
        BankAccount("Alice","qwe123",23),
        BankAccount("Bob","7897",100),
        BankAccount("Kenny","dsk")
    };

    account_list[1].Deposit(22);

    for(int i = 0;i<3;i++)
        account_list[i].Show();
    */

    /*
    //10-2
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy","Sam");

    one.Show();
    one.FormalShow();
    cout<<endl;

    two.Show();
    two.FormalShow();
    cout<<endl;

    three.Show();
    three.FormalShow();
    cout<<endl;
    */

    /*
    //10-5
    Customer c1 = {"abc",12};
    Customer c2 = {"sss",10};
    Stack s1;
    s1.Push(c1);
    s1.Push(c2);
    double total = 0;
    Customer temp;
    while(!s1.IsEmpty())
    {
        s1.Pop(temp);
        total += temp.payment;
    }
    cout<<total;
    */

    /*
    //10-8
    using namespace LIST;
    List l;
    int count = 0;
    while(!l.IsFull())
    {
        l.Add(count);
        count++;
    }
    l.Visit(show);
    l.Visit(add);
    l.Visit(show);
    */

    return 0;
}

