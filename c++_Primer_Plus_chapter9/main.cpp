#include <iostream>
#include <string>
#include <new>
#include <cstring>
#include "c++_Primer_Plus_chapter8.h"

using namespace std;

char buffer[BUF];

int main()
{
    /*
    //9-1
    golf g1,g2;

    setgolf(g1,"this is g1",1);
    int test = 0;
    test = setgolf(g2);
    while(!test)
    {
        cout<<"Empty name. Please input again:\n";
        test = setgolf(g2);
    }
    showgolf(g1);
    showgolf(g2);

    handicap(g1,99);
    showgolf(g1);
    */

    /*
    //9-2
    string input;
    cout<<"Enter a line:\n";
    getline(cin,input);
    while(cin)  //Ctrl+z is a simulink of EOF on console to end the program
    {
        strcount(input);
        cout<<"Enter the next line:\n";
        getline(cin,input);
    }
    cout<<"Bye.\n";
    */

    /*
    //9-3
    chaff *chaff_tbl = new (buffer) chaff[2];
    strcpy(chaff_tbl[0].dross,"garbage");
    chaff_tbl[0].slag = 123;
    strcpy(chaff_tbl[1].dross,"trash");
    chaff_tbl[1].slag = 666;

    for(int i = 0;i<2;i++)
    {
        cout<<i<<":"<<endl;
        cout<<chaff_tbl[i].dross<<"\t"<<chaff_tbl[i].slag<<endl;
    }
    */

    /*
    //9-4
    using namespace SALES;

    Sales s1,s2;
    const double ar[4]= {1,2,3,4};
    setSales(s1,ar,4);
    setSales(s2);
    showSales(s1);
    showSales(s2);
    */

    return 0;
}
