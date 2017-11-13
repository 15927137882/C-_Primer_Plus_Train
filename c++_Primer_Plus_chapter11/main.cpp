#include "c++_Primer_Plus_chapter11.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
    /*
    //11-1 && 11-2
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    ofstream fout;
    fout.open("Result.txt");
    cout<<"Enter target distance: ";
    cin>>target;
    cout<<"Enter step length: ";
    cin>>dstep;
    fout<<"Target Distance: "<<target<<", Step Size: "<<dstep<<endl;

    fout<<steps<<": "<<result<<endl;
    while(result.magval() < target)
    {
        direction = rand() % 360;
        step.reset(dstep,direction,Vector::POL);
        result = result + step;
        steps++;
        fout<<steps<<": "<<result<<endl;
    }
    fout<<"After "<<steps<<" steps, the subject has the following location:\n"
        <<result<<"\nor\n";

    result.polar_mode();

    fout<<result<<endl
        <<"Average outward distance per step = "
        <<(target / steps);

    fout.close();
    */

    /*
    //11-3
    using VECTOR::Vector;
    int N = 0;
    double target;
    double dstep;
    cout<<"Enter iterator times: \n";
    cin>>N;
    cout<<"Enter target distance: \n";
    cin>>target;
    cout<<"Enter step length: \n";
    cin>>dstep;
    double total_steps = 0;
    double max_steps = 0;
    double min_steps = (numeric_limits<double>::max)();
    int count = N;
    while(count--)
    {
        srand(time(0) + unsigned(1000*count));  //to make sure we can get relatively random number sequence
        double direction;
        Vector step;
        Vector result(0.0,0.0);
        unsigned long steps = 0;

        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep,direction,Vector::POL);
            result = result + step;
            steps++;
        }
        total_steps += steps;
        if(steps > max_steps) max_steps = steps;
        if(steps < min_steps) min_steps = steps;
    }
    cout<<"Max steps: "<<max_steps<<endl;
    cout<<"Min steps: "<<min_steps<<endl;
    cout<<"Average steps: "<<total_steps/N<<endl;
    */

    /*
    //11-4
    using namespace TIME;
    Time aida(3,35);
    Time tosca(2,48);
    Time temp;

    cout<<"Aida and Tosca:\n";
    cout<<aida<<"; "<<tosca<<endl;
    temp = aida+tosca;
    cout<<"Aida + Tosca: "<<temp<<endl;
    temp = aida * 1.17;
    cout<<"Aida * 1.17: "<<temp<<endl;
    cout<<"10.0 * Tosca: "<<10.0*tosca<<endl;
    */

    /*
    //11-5
    using namespace STONEWET;
    Stonewt wolfe(285.7);
    cout<<wolfe<<endl;
    wolfe.SetFormat(Stonewt::intp);
    cout<<wolfe<<endl;
    wolfe.SetFormat(Stonewt::st);
    cout<<wolfe<<endl;
    Stonewt nice(10.0);
    Stonewt cool = 2*wolfe;
    cout<<cool<<endl;
    */

    /*
    //11-6
    using namespace STONEWET;
    Stonewt tbl[6] =
    {
        Stonewt(2),
        Stonewt(4),
        Stonewt(669)
    };

    Stonewt comp(11,0.0);
    for(int i = 3;i<6;i++)
    {
        cout<<"Enter the pounds: ";
        double pounds;
        cin>>pounds;
        tbl[i] = Stonewt(pounds);
    }



    int count = 0;
    Stonewt min = tbl[0];
    Stonewt max = tbl[0];
    if(tbl[0]>=comp) count++;
    for(int i = 1;i<6;i++)
    {
        if(min>tbl[i]) min = tbl[i];
        if(max<tbl[i]) max = tbl[i];
        if(tbl[i]>=comp) count++;
    }

    cout<<"Max: "<<max<<endl
        <<"Min: "<<min<<endl
        <<"Number larger than 11 stones: "<<count<<endl;
    */

    /*
    //11-7
    using namespace COMPLEX;
    complex a(3.0,4.0);
    complex c(1.0,1.0);
    cout<<"Enter a complex number (q to quit):\n";
    while(cin>>c)
    {
        cout<<"c is "<<c<<"\n";
        cout<<"complex conjugate number is "<<~c<<'\n';
        cout<<"a is "<<a<<"\n";
        cout<<"a + c is "<<a + c<<"\n";
        cout<<"a - c is "<<a - c<<"\n";
        cout<<"a * c is "<<a * c<<"\n";
        cout<<"2 * c is "<<2*c<<"\n";
        cout<<"Enter a complex number (q to quit):\n";
    }
    cout<<"Done!\n";
    */


    return 0;
}
