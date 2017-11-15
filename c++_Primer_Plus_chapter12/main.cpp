#include <iostream>
#include "c++_Primer_Plus_chapter12.h"
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main()
{
    /*
    //12-1
    {
    using namespace COW;
    Cow c1;
    Cow c2("abcdefghijklmnopqrstuvwxyz","eat grass",200);
    Cow c3("Black Horn","fight",123);
    c1 = c2;
    Cow c4 = c3;

    c1.ShowCow();
    cout<<endl;
    c2.ShowCow();
    cout<<endl;
    c3.ShowCow();
    cout<<endl;
    c4.ShowCow();
    cout<<endl;
    }
    */

    /*
    //12-2
    using namespace STRING;
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout<<s2;
    cin>>s3;
    s2 = "My name is " + s3;
    cout<<s2<<".\n";
    s2 = s2 + s1;
    s2.Stringup();
    cout<<"The string\n"<<s2<<"\ncontains "<<s2.Has('A')
        <<" 'A' characters in it.\n";
    s1 = "red";

    String rgb[3] = {String(s1),String("green"),String("blue")};
    cout<< "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while(cin>>ans)
    {
        ans.Stringlow();
        for(int i = 0;i<3;i++)
        {
            if(ans == rgb[i])
            {
                cout<<"That's right!\n";
                success = true;
                break;
            }
        }
        if(success) break;
        else cout<<"Try again!\n";
    }
    cout<<"Bye\n";
    */

    using namespace ATM;
    srand(time(0));

    /*

    cout<<"Case Study: Bank of Heather Automatic Teller\n";
    cout<<"Enter maximum size of queue: ";
    int qs;
    cin>>qs;
    Queue line(qs);

    cout<<"Enter the number of simulation hours: ";
    int hours;
    cin>>hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout<<"Enter the average number of customers per hour: ";
    double perhour;
    cin>>perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for(int cycle = 0;cycle < cyclelimit;cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if(line.isfull()) turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enque(temp);
            }
        }
        if(wait_time<=0 && !line.isempty())
        {
            line.deque(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if(wait_time > 0) wait_time--;
        sum_line += line.queuecount();
    }

    if(customers > 0)
    {
        cout<<"customers accepted: "<<customers<<endl;
        cout<<"  customers served: "<<served<<endl;
        cout<<"         turnaways: "<<turnaways<<endl;
        cout<<"average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<double(sum_line) / cyclelimit<<endl;
        cout<<" average wait time: "
            <<double(line_wait) / served <<" minutes\n";
    }
    else
        cout<<"No customers!\n";
    cout<<"Done!\n";
    */

    /*
    //12-5
    cout<<"Case Study: Bank of Heather Automatic Teller\n";
    cout<<"Enter maximum size of queue: ";
    int qs;
    cin>>qs;
    Queue line(qs);

    double perhour = 0;
    int wait_time;
    long line_wait;
    long served = 0;
    do
    {
        perhour++;
        double min_per_cust;
        min_per_cust = MIN_PER_HR / perhour;

        Item temp;
        long turnaways = 0;
        long customers = 0;
        served = 0;
        long sum_line = 0;
        wait_time = 0;
        line_wait = 0;

        long cyclelimit = MIN_PER_HR * 100;

        for(int cycle = 0;cycle < cyclelimit;cycle++)
        {
            if(newcustomer(min_per_cust))
            {
                if(line.isfull()) turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enque(temp);
                }
            }
            if(wait_time<=0 && !line.isempty())
            {
                line.deque(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time > 0) wait_time--;
            sum_line += line.queuecount();
        }

    } while(double(line_wait) / served <= 1);

    cout<<"To keep the average wait time no larger than 1 minute.\n"
        <<"The customer arrival rate should no larger than "<<perhour
        <<" person per hour"<<endl;

    */


    /*
    //12-6
    cout<<"Case Study: Bank of Heather Automatic Teller(Double ATMs)\n";
    cout<<"Enter maximum size of queue: ";
    int qs;
    cin>>qs;
    Queue line1(qs);
    Queue line2(qs);

    double perhour = 0;
    int wait_time1,wait_time2;
    long line_wait;
    long served = 0;
    do
    {

        perhour++;
        double min_per_cust;
        min_per_cust = MIN_PER_HR / perhour;

        Item temp;
        long turnaways = 0;
        long customers = 0;
        served = 0;
        long sum_line = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line_wait = 0;

        long cyclelimit = MIN_PER_HR * 100;

        for(int cycle = 0;cycle < cyclelimit;cycle++)
        {
            if(newcustomer(min_per_cust))
            {
                if(line1.isfull() && line2.isfull()) turnaways++;
                else if(line1.queuecount() < line2.queuecount())
                {
                    customers++;
                    temp.set(cycle);
                    line1.enque(temp);
                }
                else
                {
                    customers++;
                    temp.set(cycle);
                    line2.enque(temp);
                }
            }
            if(wait_time1<=0 && !line1.isempty())
            {
                line1.deque(temp);
                wait_time1 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time2<=0 && !line2.isempty())
            {
                line2.deque(temp);
                wait_time2 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time1 > 0) wait_time1--;
            if(wait_time2 > 0) wait_time2--;
            sum_line += line1.queuecount();
            sum_line += line2.queuecount();
        }
    } while(double(line_wait) / served <= 1);

    cout<<"To keep the average wait time no larger than 1 minute.\n"
        <<"The customer arrival rate should no larger than "<<perhour
        <<" person per hour"<<endl;
    */

    return 0;
}

bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}
