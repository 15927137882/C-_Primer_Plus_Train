#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Donater
{
    string name;
    double money;
    bool grand = false;
};

bool isvowels(char ch);

int main()
{
    /*
    //6-1
    char ch = {};
    cin.get(ch);
    while(ch != '@')
    {
        if(isdigit(ch) || isspace(ch))
        {
            if(ch == '\n') cout<<ch;
            cin.get(ch);
            continue;
        }
        else if(isupper(ch))
            cout<<char(tolower(ch));
        else if(islower(ch))
            cout<<char(toupper(ch));
        else
            cout<<ch;
        cin.get(ch);
    }
    */

    /*
    //6-3
    const char *tbl [] =
    {
        "carnivore",
        "pianist",
        "tree",
        "game"
    };
    char choice = {};
    int index = {};
    cout<<"Please enter a c,p,t, or g: ";
loop:
    cin>>choice;
    switch(choice)
    {
        case 'c': index = 0;
                  break;
        case 'p': index = 1;
                  break;
        case 't': index = 2;
                  break;
        case 'g': index = 3;
                  break;
        default : cout<<"Please enter a c,p,t, or g: ";
                  goto loop;
                  break;
    }
    cout<<"A maple is a "<<tbl[index]<<endl;
    */

    /*
    //6-5
    double revenue = {},tax = {};
    cin>>revenue;
    if(revenue <= 5000) tax = 0;
    else if(revenue >= 5001 && revenue <= 15000) tax = (revenue-5000)*0.1;
    else if(revenue >= 15001 && revenue <=35000) tax = 10000*0.1 + (revenue-15000)*0.15;
    else tax = 10000*0.1 + 20000*0.15 + (revenue-35000)*0.2;
    cout<<tax<<endl;
    */

    /*
    //6-7
    string input = {};
    int others = 0, vowels = 0 ,consonants = 0;
    cout<<"Enter the words (q to quit):\n";
    cin>>input;
    while(input != "q")
    {
        if(!isalpha(input[0])) ++others;
        else if(isvowels(input[0])) ++vowels;
        else ++consonants;
        cin>>input;
    }
    cout<<vowels<<" words beginning with vowels\n";
    cout<<consonants<<" words beginning with consonants\n";
    cout<<others<<" others\n";
    */

    /*
    //6-8
    ifstream fin;
    string filename;
    cout<<"Input filename\n";
    cin>>filename;
    fin.open(filename);
    int count = {};
    char ch;
    if(!fin.is_open())
    {
        cout<<"ERROR\n";
        cin.get();
        cin.get();
        exit(EXIT_FAILURE);
    }
    while(fin>>ch)
        ++count;
    cout<<count<<endl;
    fin.close();
    cin.get();
    cin.get();
    */

    /*
    //6-6 & 6-9
    ifstream fin;
    string filename;
    cout<<"Input filename\n";
    cin>>filename;
    fin.open(filename);
    if(!fin.is_open())
    {
        cout<<"ERROR\n";
        exit(EXIT_FAILURE);
    }
    int num = {};
    fin>>num;
    fin.get();      //remember to eat the linefeed
    Donater *donater_tbl = new Donater[num];
    for(int i = 0;i<num;i++)
    {
        getline(fin,donater_tbl[i].name);
        fin>>donater_tbl[i].money;
        fin.get();  //remember to eat the linefeed
    }
    int num_grand = {},num_patron = {};
    for(int i = 0;i<num;i++)
    {
        if(donater_tbl[i].money > 10000)
        {
            donater_tbl[i].grand = true;
            ++num_grand;
        }
        else ++num_patron;
    }
    cout<<"Grand Patrons:\n";
    if(num_grand == 0) cout<<"none\n";
    else
    {
        for(int i = 0;i<num;i++)
        {
            if(donater_tbl[i].grand == true)
                cout<<donater_tbl[i].name<<endl;
        }
    }
    cout<<"\n\nPatrons:\n";
    if(num_patron == 0) cout<<"none\n";
    else
    {
        for(int i = 0;i<num;i++)
        {
            if(donater_tbl[i].grand == false)
                cout<<donater_tbl[i].name<<endl;
        }
    }

    delete [] donater_tbl;
    */


    return 0;
}


bool isvowels(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return true;
    return false;
}
