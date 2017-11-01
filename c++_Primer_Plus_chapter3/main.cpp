#include <iostream>

using namespace std;

int main()
{
    /*
    // 3-3
    int degree,minute,second;

    cout<<"Enter a latitude in degrees, minutes, and seconds:\n"
        <<"First, enter the degrees: ";
    cin>>degree;
    cout<<"Next, enter the minutes of the arc: ";
    cin>>minute;
    cout<<"Finally, enter the seconds of the arc: ";
    cin>>second;

    double result;
    result = second/(3600.0) + minute/(60.0) + double(degree);
    cout<<degree<<" degrees, "<<minute<<" minutes, "<<second
        <<" seconds = "<<result<<" degrees\n";
    */

    /*
    //3-4
    const int day2hour = 24;
    const int hour2minute = 60;
    const int minute2second = 60;
    const int day2second = day2hour * hour2minute * minute2second;
    const int hour2second = hour2minute * minute2second;

    long long time;
    cout<<"Enter the number of seconds: ";
    cin>>time;

    cout<<time<<" seconds = ";

    int days = time / day2second;
    time -= days*day2second;

    int hours = time / hour2second;
    time -= hours*hour2second;

    int minutes = time / minute2second;
    time -= minutes*minute2second;

    int seconds = time;

    cout<<days<<" days, "<<hours<<" hours, "<<minutes
        <<" minutes, "<<seconds<<" seconds.\n";

    */

    /*
    //3-5
    long long worldpop,USpop;
    cout<<"Enter the world's population: ";
    cin>>worldpop;
    cout<<"Enter the population of the US:";
    cin>>USpop;

    double result = (double(USpop) / double(worldpop)) * 100;

    cout<<"The population of the US is "<<result
        <<"% of the world population.\n";
    */

    return 0;
}
