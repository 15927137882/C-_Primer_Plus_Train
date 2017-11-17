#include "c++_Primer_Plus_chapter13.h"
#include <cstring>
#include <iostream>

using namespace std;

Cd::Cd()
{
    performance = label = nullptr;
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const char *s1,const char *s2,int n,double x) : selections(n),playtime(x)
{
    int len = strlen(s1);
    performance = new char[len+1];
    strcpy(performance,s1);

    len = strlen(s2);
    label = new char[len+1];
    strcpy(label,s2);
}

Cd::Cd(const Cd &d) : selections(d.selections),playtime(d.playtime)
{
    int len = strlen(d.performance);
    performance = new char[len+1];
    strcpy(performance,d.performance);

    len = strlen(d.label);
    label = new char[len+1];
    strcpy(label,d.label);
}

Cd::~Cd()
{
    delete [] performance;
    delete [] label;
}


void Cd::Report() const
{
    cout<<"Label: "<<label<<endl;
    cout<<"Performance: "<<performance<<endl;
    cout<<"Selections: "<<selections<<endl;
    cout<<"Playtime: "<<playtime<<endl<<endl;
}


Cd & Cd::operator=(const Cd &d)
{
    if(this == &d) return *this;
    delete [] performance;
    delete [] label;

    int len = strlen(d.performance);
    performance = new char[len+1];
    strcpy(performance,d.performance);

    len = strlen(d.label);
    label = new char[len+1];
    strcpy(label,d.label);

    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic() : Cd()
{
    production = nullptr;
}

Classic::Classic(const char *s0,const char *s1,const char *s2,int n,double x) : Cd(s1,s2,n,x)
{
    int count = 0;
    for(int i = 0;s0[i] != '\0';i++)
        if(s0[i] == ',') count++;
    count++;
    int *num = new int[count];
    for(int i = 0;i<count;i++) num[i] = 0;
    int j = 0;
    for(int i = 0;s0[i] != '\0';)
    {
        if(s0[i] == ',')
        {
            j++;
            while(s0[++i] == ' ') ;
            continue;
        }
        num[j]++;
        i++;
    }

    production = new char*[count+1];
    production[count] = nullptr;

    for(int i = 0;i<count;i++)
    {
        production[i] = new char[num[i]+1];
    }

    j = 0;
    int numc = 1;
    for(int i = 0;s0[i] != '\0';)
    {
        if(s0[i] == ',')
        {
            while(s0[++i] == ' ') ;
            continue;
        }
        if(numc == num[j]+1)
        {
            production[j][numc-1] = '\0';
            j++;
            numc = 1;
        }
        production[j][numc-1] = s0[i];
        numc++;
        i++;
    }
    production[count-1][num[count-1]] = '\0';


    delete [] num;
}


Port::Port(const char *br,const char *st,int b)
{
    brand = new char[strlen(br)+1];
    strcpy(brand,br);
    strcpy(style,st);
    bottles = b;
}

Port::Port(const Port &p)
{
    brand = new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port &p)
{
    if(this == &p) return *this;
    delete [] brand;
    brand = new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles = bottles-b>=0 ? bottles-b : 0;
    return *this;
}

ostream & operator<<(ostream & os,const Port & p)
{
    os<<p.brand<<", "<<p.style<<", "<<p.bottles;
    return os;
}

void Port::Show() const
{
    cout<<"Brand: "<<brand<<endl;
    cout<<"Kind: "<<style<<endl;
    cout<<"Bottles: "<<bottles<<endl;
}


VintagePort::VintagePort() : Port("none","vintage",0)
{
    nickname = new char[5];
    strcpy(nickname,"none");
    year = 0;
}

void VintagePort::Show() const
{
    Port::Show();
    cout<<"Nickname: "<<nickname<<endl;
    cout<<"Year: "<<year<<endl;
}

VintagePort::VintagePort(const char *br,int b,const char *nn,int y) : Port(br,"vintage",b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname,nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname,vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort &vp)
{
    if(this == &vp) return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname,vp.nickname);
    year = vp.year;
    return *this;
}


Classic::~Classic()
{
    int i = 0;
    if(production != nullptr)
    {
        while(production[i] != nullptr)
        {
            delete [] production[i];
            i++;
        }
    }
    delete [] production;
}

ostream & operator<<(ostream & os,const VintagePort &vp)
{
    os << dynamic_cast<const Port &>(vp);
    os <<", "<<vp.nickname<<", "<<vp.year;
    return os;
}


void Classic::Report() const
{
    Cd::Report();
    cout<<"Main Products:\n";
    char **temp = production;
    while(*temp != nullptr)
    {
        cout<<*temp<<endl;
        temp++;
    }
    cout<<endl;
}

Classic & Classic::operator=(const Classic &c)
{
    if(this == &c) return *this;
    Cd::operator=(c);

    int i = 0;
    if(production != nullptr)
    {
        while(production[i] != nullptr)
        {
            delete [] production[i];
            i++;
        }
    }
    delete [] production;

    int k = 0;
    int count = 0;
    while(c.production[k++] != nullptr) count++;
    production = new char*[count+1];
    production[count] = nullptr;
    for(int i = 0;i<count;i++)
    {
        production[i] = new char[strlen(c.production[i])+1];
        strcpy(production[i],c.production[i]);
    }

    return *this;

}
