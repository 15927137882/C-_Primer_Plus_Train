#include "c++_Primer_Plus_chapter11.h"
#include <cmath>

namespace VECTOR
{
    using std::cout;
    using std::ostream;

    const double Rad_to_deg = 45.0 / atan(1.0);

    double Vector::get_mag() const
    {
        return sqrt(x*x + y*y);
    }

    double Vector::get_ang() const
    {
        if(x == 0.0 && y == 0.0) return 0.0;
        else return atan2(y,x);
    }

    void Vector::set_x()
    {
    }

    void Vector::set_y()
    {
    }

    Vector::Vector(double n1,double n2, Mode form)
    {
        mode = form;
        if(form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if(form == POL)
        {
            x = n1 * cos(n2);
            y = n1 * sin(n2);
        }
        else
        {
            cout<< "Incorrect 3rd argument to Vector() -- ";
            cout<<"vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1,double n2, Mode form)
    {
        mode = form;
        if(form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if(form == POL)
        {
            x = n1 * cos(n2);
            y = n1 * sin(n2);
        }
        else
        {
            cout<< "Incorrect 3rd argument to Vector() -- ";
            cout<<"vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector()
    {
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x+b.x,y+b.y);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x-b.x,y-b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x,-y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n*x,n*y);
    }

    Vector operator*(double n, const Vector &a)
    {
        return a*n;
    }

    ostream & operator<<(ostream &os,const Vector &v)
    {
        if(v.mode == Vector::RECT)
            os<<"(x,y) = ("<<v.x<<", "<<v.y<<")";
        else if(v.mode == Vector::POL)
        {
            os<<"(m,a) = ("<<v.get_mag()<<", "
                <<v.get_ang() * Rad_to_deg<<")";
        }
        else os<<"Vector object mode is invalid";
        return os;
    }
}


namespace TIME
{
    Time::Time()
    {
        hours = minutes = 0;
    }

    Time::Time(int h,int m)
    {
        hours = h;
        minutes = m;
    }

    void Time::AddMin(int m)
    {
        minutes += m;
        hours += minutes / 60;
        minutes %= 60;
    }

    void Time::AddHr(int h)
    {
        hours += h;
    }

    void Time::Reset(int h,int m)
    {
        hours = h;
        minutes = m;
    }

    Time operator+(const Time &t1,const Time &t2)
    {
        Time sum;
        sum.minutes = t1.minutes + t2.minutes;
        sum.hours = t1.hours + t2.hours + sum.minutes/60;
        sum.minutes %= 60;
        return sum;
    }

    Time operator-(const Time &t1,const Time &t2)
    {
        Time diff;
        int tot1,tot2;
        tot1 = t1.minutes + 60*t1.hours;
        tot2 = t2.minutes + 60*t2.hours;
        diff.minutes = (tot2 - tot1) % 60;
        diff.hours = (tot2 - tot1) / 60;
        return diff;
    }

    Time operator*(double n,const Time &t)
    {
        Time result;
        long totalminutes = t.hours*n*60 + t.minutes*n;
        result.hours = totalminutes / 60;
        result.minutes = totalminutes % 60;
        return result;
    }

    Time operator*(const Time &t,double n)
    {
        return n*t;
    }

    std::ostream & operator<<(std::ostream &os,const Time &t)
    {
        os<<t.hours<<" hours, "<<t.minutes<<" minutes";
        return os;
    }

}


namespace STONEWET
{
    Stonewt::Stonewt(double lbs)
    {
        stone = int(lbs) / Lbs_per_stn;
        pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
        pounds = lbs;
        show_format = flp;
    }

    Stonewt::Stonewt(int stn,double lbs)
    {
        stone = stn;
        pds_left = lbs;
        pounds = stn*Lbs_per_stn + lbs;
        show_format = flp;
    }

    Stonewt::Stonewt()
    {
        stone = pounds = pds_left = 0;
        show_format = flp;
    }

    Stonewt::~Stonewt()
    {
    }

    std::ostream & operator<<(std::ostream &os,const Stonewt &s)
    {
        switch(s.show_format)
        {
            case Stonewt::st   : os<<s.stone<<" stone, "<<s.pds_left<<" pounds\n";
                                 break;
            case Stonewt::intp : os<<int(s.pounds+0.5)<<" pounds\n";
                                 break;
            case Stonewt::flp  : os<<s.pounds<<" pounds\n";
            default            : break;
        }
        return os;
    }

    Stonewt Stonewt::operator+(const Stonewt &s) const
    {
        return Stonewt(pounds+s.pounds);
    }

    Stonewt Stonewt::operator-(const Stonewt &s) const
    {
        double diff = pounds-s.pounds>0 ? pounds-s.pounds : 0;
        return Stonewt(diff);
    }

    Stonewt Stonewt::operator*(double n) const
    {
        return Stonewt(n*pounds);
    }

    Stonewt operator*(double n,const Stonewt &s)
    {
        return s*n;
    }

    bool Stonewt::operator>(const Stonewt &s) const
    {
        return pounds > s.pounds;
    }

    bool Stonewt::operator<(const Stonewt &s) const
    {
        return pounds < s.pounds;
    }

    bool Stonewt::operator>=(const Stonewt &s) const
    {
        return pounds >= s.pounds;
    }

    bool Stonewt::operator<=(const Stonewt &s) const
    {
        return pounds <= s.pounds;
    }

    bool Stonewt::operator==(const Stonewt &s) const
    {
        return pounds == s.pounds;
    }

    bool Stonewt::operator!=(const Stonewt &s) const
    {
        return pounds != s.pounds;
    }

}

namespace COMPLEX
{
    complex::complex(double a,double b)
    {
        real = a;
        imaginary = b;
    }

    complex::~complex()
    {
    }

    complex complex::operator~()
    {
        return complex(real,-imaginary);
    }

    complex complex::operator+(const complex &b)
    {
        return complex(real+b.real,imaginary+b.imaginary);
    }

    complex complex::operator-(const complex &b)
    {
        return complex(real-b.real,imaginary-b.imaginary);
    }

    complex complex::operator*(double multi) const
    {
        return complex(multi*real,multi*imaginary);
    }

    complex complex::operator*(const complex &b)
    {
        return complex(real*b.real-imaginary*b.imaginary ,
                       imaginary*b.real+real*b.imaginary);
    }


    complex operator*(double n,const complex &b)
    {
        return b*n;
    }



    std::ostream & operator<<(std::ostream &os,const complex &b)
    {
        os<<"("<<b.real<<","<<b.imaginary<<"i)";
        return os;
    }

    std::istream & operator>>(std::istream &is,complex &b)
    {
        using std::cout;
        cout<<"real: ";
        is>>b.real;
        cout<<"imaginary: ";
        is>>b.imaginary;
        return is;
    }
}
