#include <iostream>
#include "c++_Primer_Plus_chapter13.h"

using namespace std;

void Bravo(const Cd &disk);

int main()
{

    /*
    //13-1 && 13-2
    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel",
               "Philips",2,57.17);

    Cd *pcd = &c1;

    cout<<"Using object directly:\n";
    c1.Report();
    c2.Report();

    cout<<"Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout<<"Calling a functiong with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout<<"Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    */

    /*
    //13-4
    Port p("Gallo","twany",20);
    p.Show();
    p+=10;
    cout<<p;
    Port q;
    q = p;
    q-=100;
    cout<<q;


    VintagePort vp1;
    cout<<vp1;
    vp1+=10;
    cout<<vp1;
    */

    return 0;
}


void Bravo(const Cd &disk)
{
    disk.Report();
}
