#ifndef C_PRIMER_PLUS_CHAPTER8_H_INCLUDED   //remember '+' shouldn't appear in macro definition
#define C_PRIMER_PLUS_CHAPTER8_H_INCLUDED

#include <string>

const int Len = 40;
const int Arsize = 10;
const int BUF = 1024;

struct golf
{
    char fullname[Len];
    int handicap;
};

struct chaff
{
    char dross[20];
    int slag;
};

void setgolf(golf &g,const char * name,int hc);
int setgolf(golf &g);
void handicap(golf &g,int hc);

void showgolf(const golf &g);

void strcount(const std::string &str);

namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };

    void setSales(Sales &s,const double ar[],int n);
    void setSales(Sales &s);
    void showSales(const Sales &s);
}


#endif // C++_PRIMER_PLUS_CHAPTER8_H_INCLUDED
