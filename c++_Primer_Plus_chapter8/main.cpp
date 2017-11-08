#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

struct stringy
{
    char * str;
    int ct;
};

void printstr(char *str,int n = 0);
string & trans_to_upper(string &str);
void set(stringy &str,const char *p);
void show(const stringy &str,int n = 1);
void show(const char *p,int n = 1);

template <typename T>
T max5(T input[5]);

template <typename T>
T maxn(T input[],int n);

template <>
const char * maxn(const char *p[],int n);

int main()
{
    /*
    //8-1
    char str1[20] = "abc";
    char str2[20] = "def";
    printstr(str1);
    printstr(str2,1);
    printstr(str1);
    printstr(str2,9);
    */

    /*
    //8-3
    cout<<"Enter a string (q to quit): ";
    string str;
    getline(cin,str);
    while(str != "q")
    {
        cout<<trans_to_upper(str);
        cout<<endl<<"Next string (q to quit): ";
        getline(cin,str);
    }
    cout<<"Bye.\n";
    */

    /*
    //8-4
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany,testing);
    show(beany);
    show(beany,2);

    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Done!");
    */

    /*
    //8-5
    int in[5] = {2,4,5,2,1};
    double dou[5] = {55.5,66.6,44.4,11.1,33.3};

    cout<<max5(in)<<"\t"<<max5(dou)<<endl;
    */

    /*
    //8-6
    int intar[6] = {1,2,6,3,4,5};
    double douar[4] = {66.6,33.3,77.7,1.2};
    const char *str[5] =
    {
        "abc",
        "abcd",
        "erfgt",
        "dddff",
        "as"
    };

    cout<<maxn(intar,6)<<"\t"<<maxn(douar,4)<<"\t"<<maxn(str,5)<<endl;
    */

    return 0;
}


void printstr(char *str,int n)
{
    static int count = 1;
    if(n == 0) cout<<str<<endl;
    else
    {
        for(int i = 0;i<count;i++)
        {
            cout<<str<<endl;
        }
    }
    count++;
}

string & trans_to_upper(string &str)
{
    for(int i = 0;str[i];i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

void set(stringy &str,const char *p)
{
    str.str = new char[strlen(p) + 1];
    strcpy(str.str,p);
    str.ct = strlen(str.str);
}

void show(const stringy &str,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<str.str<<endl;
    }
}

void show(const char *p,int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<p<<endl;
    }
}

template <typename T>
T max5(T input[5])
{
    T temp;
    temp = input[0];
    for(int i = 1;i<5;i++)
        if(temp < input[i]) temp = input[i];
    return temp;
}

template <typename T>
T maxn(T input[],int n)
{
    T temp;
    temp = input[0];
    for(int i = 1;i < n;i++)
        if(temp < input[i]) temp = input[i];
    return temp;
}

template <>
const char * maxn(const char *p[],int n)
{
    const char *temp = p[0];
    unsigned int len = strlen(temp);
    for(int i = 1;i<n;i++)
    {
        if(len < strlen(p[i]))
        {
             temp = p[i];
             len = strlen(p[i]);
        }
    }
    return temp;
}
