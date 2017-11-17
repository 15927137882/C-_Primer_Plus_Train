#ifndef C_PRIMER_PLUS_CHAPTER13_H_INCLUDED
#define C_PRIMER_PLUS_CHAPTER13_H_INCLUDED

#include <iostream>
using std::ostream;


class Cd
{
private:
    char *performance;
    char *label;
    int selections;
    double playtime;
public:
    Cd();
    Cd(const char *s1,const char *s2,int n,double x);
    Cd(const Cd &d);
    virtual ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd &d);
};


class Classic : public Cd
{
private:
    char **production;      //dual-pointer technical
public:
    Classic(const char *s0,const char *s1,const char *s2,int n,double x);
    Classic();
    ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic &c);
};

class Port
{
private:
    char *brand;
    char style[20];
    int bottles;
public:
    Port(const char *br = "none",const char * st = "none",int b = 0);
    Port(const Port &p);
    virtual ~Port() { delete [] brand;}
    Port & operator=(const Port &p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount() const {return bottles;}
    virtual void Show() const;
    friend ostream & operator<<(ostream & os,const Port & p);
};

class VintagePort : public Port
{
private:
    char *nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char *br,int b,const char *nn,int y);
    VintagePort(const VintagePort &vp);
    ~VintagePort() {delete [] nickname;}
    VintagePort & operator=(const VintagePort &vp);
    virtual void Show() const;
    friend ostream & operator<<(ostream & os,const VintagePort &vp);

};

#endif // C++_PRIMER_PLUS_CHAPTER13_H_INCLUDED
