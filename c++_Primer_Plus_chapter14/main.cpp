#include <iostream>
#include <cstring>
#include "c++_Primer_Plus_chapter14.h"


using namespace std;

const int SIZE = 5;

int main()
{
    /*
    //14-1
    cout<<"Enter name of wine: ";
    char lab[50];
    cin.getline(lab,50);
    cout<<"Enter number of years: ";
    int yrs;
    cin>>yrs;

    Wine holding(lab,yrs);
    holding.Getbottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = {1993,1995,1998};
    int b[YRS] = {48,60,72};
    Wine more("Gushing Grape Red",YRS,y,b);
    more.Show();
    cout<<"Total bottles for "<<more.Label()
        <<": "<<more.Sum()<<endl;
    cout<<"Bye\n";
    return 0;
    */

    /*
    //14-2
    cout<<"Enter name of wine: ";
    char lab[50];
    cin.getline(lab,50);
    cout<<"Enter number of years: ";
    int yrs;
    cin>>yrs;

    Wine_pr holding(lab,yrs);
    holding.Getbottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = {1993,1995,1998};
    int b[YRS] = {48,60,72};
    Wine_pr more("Gushing Grape Red",YRS,y,b);
    more.Show();
    cout<<"Total bottles for "<<more.Label()
        <<": "<<more.Sum()<<endl;
    cout<<"Bye\n";
    */

    /*
    //14-3
    QueueTp<Worker *> WorkerQue;
    Worker * lolas[SIZE] = {nullptr};
    int ct;
    for(ct = 0;ct<SIZE;ct++)
    {
        char choice;
        cout<<"Enter the employee category:\n"
            <<"w: waiter s: singer  "
            <<"t: singing waiter  q: quit\n";
        cin>>choice;
        while(strchr("wstq",choice) == nullptr)
        {
            cout<<"Please enter a w, s, t, or q: ";
            cin>>choice;
        }
        if(choice == 'q') break;
        switch(choice)
        {
            case 'w':   lolas[ct] = new Waiter;
                        break;
            case 's':   lolas[ct] = new Singer;
                        break;
            case 't':   lolas[ct] = new SingingWaiter;
                        break;
        }
        cin.get();
        lolas[ct]->Set();
    }
    int i = 0;
    while(!WorkerQue.isfull() && lolas[i] != nullptr)
        WorkerQue.enqueue(lolas[i++]);

    cout<<"\nHere is your staff:\n";
    Worker *temp;
    while(WorkerQue.dequeue(temp))
    {
        cout<<endl;
        temp->Show();
    }
    cout<<"Bye.\n";
    */



    return 0;
}
