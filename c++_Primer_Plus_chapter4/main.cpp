#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Student
{
    string first_name,last_name;
    char grade;
    int age;
};

int main()
{

    /*
    //4-1
    Student student = {};
    cout<<"What is your first name?";
    getline(cin,student.first_name);
    cout<<"What is your last name?";
    getline(cin,student.last_name);
    cout<<"What letter grade do you deserve?";
    cin>>student.grade;
    cout<<"What is your age?";
    cin>>student.age;

    cout<<"Name: "<<student.last_name<<", "<<student.first_name
        <<endl<<"Grade: "<<char(student.grade + 1)
        <<endl<<"Age: "<<student.age;
    */

    /*
    //4-3
    char first_name[20],last_name[20];
    cout<<"Enter your first name: ";
    cin>>first_name;
    cout<<"Enter your last name: ";
    cin>>last_name;
    char full_name[60];
    strcat(full_name,last_name);
    strcat(full_name,", ");
    strcat(full_name,first_name);
    cout<<"Here is the information in a single string: "<<full_name<<endl;
    */

    /*
    //4-4
    string first_name,last_name;
    cout<<"Enter your first name: ";
    cin>>first_name;
    cout<<"Enter your last name: ";
    cin>>last_name;
    string full_name;
    full_name = last_name + ", " +first_name;
    cout<<"Here is the information in a single string: "<<full_name<<endl;
    */

    return 0;
}
