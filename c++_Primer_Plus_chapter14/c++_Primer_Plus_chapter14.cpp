#include "c++_Primer_Plus_chapter14.h"
#include <iostream>

using namespace std;

Wine::Wine(const char *l,int y,const int yr[],const int bot[]) : name(l),data(ArrayInt(y),ArrayInt(y)),year_num(y)
{
    for(int i = 0;i<year_num;i++)
    {
        data.first()[i] = yr[i];
        data.second()[i] = bot[i];
    }
}

Wine::Wine(const char *l,int y) : name(l),data(ArrayInt(y),ArrayInt(y)),year_num(y)
{
}

void Wine::Getbottles()
{
    cout<<"Enter "<<name<<" data for "<<year_num<<" year(s):\n";
    for(int i = 0;i<year_num;i++)
    {
        cout<<"Enter year: ";
        cin>>data.first()[i];
        cout<<"Enter bottles for that year: ";
        cin>>data.second()[i];
    }
}

const string & Wine::Label()
{
    return name;
}

int Wine::Sum()
{
    return data.second().sum();
}

void Wine::Show()
{
    cout<<"Wine: "<<name<<endl;
    cout<<"\tYear\tBottles"<<endl;
    for(int i = 0;i<year_num;i++)
        cout<<"\t"<<data.first()[i]<<"\t"<<data.second()[i]<<endl;
}

Wine_pr::Wine_pr(const char *l,int y,const int yr[],const int bot[]) : string(l), PairArray(ArrayInt(y),ArrayInt(y)),year_num(y)
{
    for(int i = 0;i<year_num;i++)
    {
        PairArray::first()[i] = yr[i];
        PairArray::second()[i] = bot[i];
    }
}

Wine_pr::Wine_pr(const char *l,int y) : string(l),PairArray(ArrayInt(y),ArrayInt(y)),year_num(y)
{

}

void Wine_pr::Getbottles()
{
    cout<<"Enter "<<(const string &)(*this)<<" data for "<<year_num<<" year(s):\n";
    for(int i = 0;i<year_num;i++)
    {
        cout<<"Enter year: ";
        cin>>PairArray::first()[i];
        cout<<"Enter bottles for that year: ";
        cin>>PairArray::second()[i];
    }
}


const string & Wine_pr::Label()
{
    return (const string &)(*this);
}

int Wine_pr::Sum()
{
    return PairArray::second().sum();
}

void Wine_pr::Show()
{
    cout<<"Wine: "<<(const string &)(*this)<<endl;
    cout<<"\tYear\tBottles"<<endl;
    for(int i = 0;i<year_num;i++)
        cout<<"\t"<<PairArray::first()[i]<<"\t"<<PairArray::second()[i]<<endl;
}

Worker::~Worker()
{
}

void Worker::Data() const
{
    cout<<"Name: "<<fullname<<endl;
    cout<<"Employee: ID:"<<id<<endl;
}

void Worker::Get()
{
    getline(cin,fullname);
    cout<<"Enter worker's ID: ";
    cin>>id;
    while(cin.get() != '\n') continue;
}


void Waiter::Set()
{
    cout<<"Enter waiter's name: ";
    Worker::Get();
    Get();
}

void Waiter::Show() const
{
    cout<< "Category: Waiter\n ";
    Worker::Data();
    Data();
}

void Waiter::Data() const
{
    cout<<"Panache rating: "<<panache<<endl;
}

void Waiter::Get()
{
    cout<< "Enter waiter's panache rating: ";
    cin>>panache;
    while(cin.get() != '\n') continue;
}

const char * Singer::pv[Singer::Vtypes] = {"other","alto","contralto","soprano","bass","baritone","tenor"};

void Singer::Set()
{
    cout<<"enter singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const
{
    cout<<"Category: singer\n";
    Worker::Data();
    Data();
}

void Singer::Data() const
{
    cout<<"Vocal range: "<<pv[voice]<<endl;
}

void Singer::Get()
{
    cout<<"Enter number for singer's vocal range:\n";
    int i;
    for(i =0;i<Vtypes;i++)
    {
        cout<<i<<": "<<pv[i]<<"   ";
        if(i%4 == 3) cout<<endl;
    }
    if(i % 4 != 0) cout<<'\n';
    cin>>voice;
    while(cin.get() != '\n') continue;
}

void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

void SingingWaiter::Set()
{
    cout<<"Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const
{
    cout<<"Category: singing waiter\n";
    Worker::Data();
    Data();
}
