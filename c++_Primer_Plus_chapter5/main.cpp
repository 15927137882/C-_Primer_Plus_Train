#include <iostream>
#include <array>
#include <string>
#include <cstring>

using namespace std;

struct Car
{
    string maker;
    int year;
};

int main()
{


    /*
    //5-1
    int input[2] = {};
    cin>>input[0]>>input[1];
    for(int i = input[0];i<input[1];i++)
    {
        input[0] = input[0] + i + 1;
    }
    cout<<input[0]<<endl;
    */

    /*
    //5-2
    array<long double,2> input = {};
    cin>>input[0]>>input[1];
    for(int i = input[0];i<input[1];i++)
    {
        input[0] = input[0] * (i + 1);
    }
    cout<<input[0]<<endl;
    */

    /*
    //5-7
    cout<<"How many cars do you wish to catalog? ";
    int num = {};
    (cin>>num).get();   //eat the line feed
    Car *car_tbl = new Car[num];
    for(int i = 0;i<num;i++)
    {
        cout<<"Car #"<<i+1<<":\n";
        cout<<"Please enter the make: ";
        getline(cin,car_tbl[i].maker);
        cout<<"Please enter the year made: ";
        (cin>>car_tbl[i].year).get();   //eat the line feed
    }
    cout<<"Here is your collection:\n";
    for(int i = 0;i<num;i++)
        cout<<car_tbl[i].year<<"\t"<<car_tbl[i].maker<<endl;
    delete [] car_tbl;
    */

    /*
    //5-8
    char input[30] = {};
    int count = {};
    cout<<"Enter words (to stop, type the word done):\n";
    cin>>input;
    while(strcmp(input,"done") != 0)
    {
        count++;
        cin>>input;
    }
    cout<<"You entered a total of "<<count<<" words"<<endl;
    */

    /*
    //5-10
    int rows = {};
    cout<<"Enter number of rows: ";
    cin>>rows;
    for(int i = 1;i<=rows;i++)
    {
        for(int j = rows-i;j>0;j--)
            cout<<'.';
        for(int j = i;j>0;j--)
            cout<<'*';
        cout<<endl;
    }
    */

    return 0;
}
