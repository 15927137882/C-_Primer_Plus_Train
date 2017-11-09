#include "c++_Primer_Plus_chapter8.h"
#include <cstring>
#include <iostream>

void setgolf(golf &g,const char * name,int hc)
{
    strcpy(g.fullname,name);
    g.handicap = hc;
}

int setgolf(golf &g)
{
    using namespace std;
    cout<<"Please input your full name: ";
   // while(cin.get() == '\n')
   //    cin.get();
    cin.getline(g.fullname,Len);
    if(g.fullname[0] == '\0')
        return 0;
    else
    {
        cout<<"Please input your handicap: ";
        cin>>g.handicap;
    }
    return 1;
}

void handicap(golf &g,int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    using namespace std;
    cout<<"Full name: "<<g.fullname<<endl;
    cout<<"Hanicap: "<<g.handicap<<endl<<endl;
}

void strcount(const std::string &str)
{
    using namespace std;
    static int total = 0;

    if(str == "")
        cout<<"Empty line.\n";
    else
    {
        cout<<"\""<<str<<"\" contains "
        <<str.size()<<"characters\n";
        total += str.size();
        cout<<total<<" characters total.\n";
    }
}

namespace SALES
{
    void setSales(Sales &s,const double ar[],int n)
    {
        n = n < 4 ? n : 4;
        double total = 0;
        for(int i = 0;i < 4;i++)
            s.sales[i] = 0.0;
        for(int i = 0;i < n;i++)
        {
            s.sales[i] = ar[i];
            total += ar[i];
        }
        s.average = total / n;

        s.max = s.min = s.sales[0];
        for(int i = 1;i < n;i++)
        {
            if(s.max < s.sales[i])
                s.max = s.sales[i];
            if(s.min > s.sales[i])
                s.min = s.sales[i];
        }
    }

    void setSales(Sales &s)
    {
        int count = 0;
        double total = 0.0;
        for(int i = 0;i < 4;i++)
            s.sales[i] = 0.0;
        std::cout<<"Please enter the data:\n";
        for(int i = 0;i<4;i++)
        {
            std::cin>>s.sales[i];
            if(std::cin)
            {
                count++;
                total += s.sales[i];
            }
            else
            {
                std::cin.clear();
                break;
            }
        }

        if(count == 0)
            s.average = 0;
        else
            s.average = total / count;

        s.max = s.min = s.sales[0];
        for(int i = 1;i < count;i++)
        {
            if(s.max < s.sales[i])
                s.max = s.sales[i];
            if(s.min > s.sales[i])
                s.min = s.sales[i];
        }
    }

    void showSales(const Sales &s)
    {
        using std::cout;
        using std::endl;

        for(int i = 0;i<4;i++)
        {
            cout<<"Season "<<i+1<<":\t"<<s.sales[i]<<endl;
        }
        cout<<"Average: "<<s.average<<endl;
        cout<<"Max: "<<s.max<<endl;
        cout<<"Min: "<<s.min<<endl;
    }

}
