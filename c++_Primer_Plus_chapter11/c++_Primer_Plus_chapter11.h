#ifndef C_PRIMER_PLUS_CHAPTER11_H_INCLUDED
#define C_PRIMER_PLUS_CHAPTER11_H_INCLUDED

#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT,POL};
    private:
        double x;
        double y;
        Mode mode;
        double get_mag() const;
        double get_ang() const;
        void set_x();
        void set_y();
    public:
        Vector(double n1 = 0.0,double n2 = 0.0, Mode form = RECT);

        void reset(double n1,double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return get_mag();}
        double angval()  const {return get_ang();}
        void polar_mode();
        void rect_mode();

        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n,const Vector &a);
        friend std::ostream & operator<<(std::ostream & os,const Vector &v);
    };
}

namespace TIME
{
    class Time
    {
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h,int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0,int m = 0);

        friend Time operator+(const Time &t1,const Time &t2);
        friend Time operator-(const Time &t1,const Time &t2);
        friend Time operator*(double n,const Time &t);
        friend Time operator*(const Time &t,double n);
        friend std::ostream & operator<<(std::ostream &os,const Time &t);
    };
}

namespace STONEWET
{
    class Stonewt
    {
    public:
        enum STATE {st,intp,flp};
    private:
        enum {Lbs_per_stn = 14};
        int stone;
        double pds_left;
        double pounds;
        STATE show_format;
    public:
        Stonewt(double lbs);
        Stonewt(int stn,double lbs);
        Stonewt();
        ~Stonewt();

        void SetFormat(STATE st) { show_format = st;}
        Stonewt operator+(const Stonewt &s) const;
        Stonewt operator-(const Stonewt &s) const;
        Stonewt operator*(double n) const;
        bool operator>(const Stonewt &s) const;
        bool operator<(const Stonewt &s) const;
        bool operator>=(const Stonewt &s) const;
        bool operator<=(const Stonewt &s) const;
        bool operator==(const Stonewt &s) const;
        bool operator!=(const Stonewt &s) const;

        friend std::ostream & operator<<(std::ostream &os,const Stonewt &s);
        friend Stonewt operator*(double n,const Stonewt &s);
    };
}

namespace COMPLEX
{
    class complex
    {
    private:
        double real;
        double imaginary;
    public:
        complex(double a= 0.0,double b= 0.0);
        ~complex();
        complex operator~();
        complex operator+(const complex &b);
        complex operator-(const complex &b);
        complex operator*(const complex &b);
        complex operator*(double multi) const;  //const is necessary ,cause friend function operator* should be consistent with this overload function

        friend complex operator*(double n,const complex &b);
        friend std::ostream & operator<<(std::ostream &os,const complex &b);
        friend std::istream & operator>>(std::istream &is,complex &b);
    };
}

#endif // C++_PRIMER_PLUS_CHAPTER11_H_INCLUDED
