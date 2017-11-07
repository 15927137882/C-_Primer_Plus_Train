#include <iostream>

using namespace std;

typedef double (*f_ptr)(double,double);

const int SLEN = 30;

struct Student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

long long factorial(long long n);
int getinfo(Student pa[],int n);
void display1(Student st);
void display2(const Student *st);
void display3(const Student pa[],int n);
double calculate(double x1,double x2,f_ptr fp);
double add(double x1,double x2);
double multiple(double x1,double x2);
double sub(double x1,double x2);

int main()
{
    /*
    //7-5
    long long n = {};
    while(cin>>n)
    {
        n = factorial(n);
        cout<<n<<endl;
    }
    */

    /*
    //7-9
    cout<<"Enter class size: ";
    int class_size;
    cin>>class_size;
    while(cin.get() != '\n')
        continue;

    Student *ptr_stu = new Student[class_size];
    int entered = getinfo(ptr_stu,class_size);
    for(int i = 0;i<entered;i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);

    }

    display3(ptr_stu,entered);
    delete [] ptr_stu;
    cout<<"Done\n";
    */

    /*
    //7-10
    const char * operator_f[3] =
    {
        "add",
        "multiple",
        "sub"
    };
    f_ptr ptr[3] = {add,multiple,sub};  //an array of function pointer
    double x1,x2,result;
    while(cin>>x1>>x2)
    {
        for(int i = 0;i<3;i++)
        {
            result = calculate(x1,x2,ptr[i]);
            cout<<operator_f[i]<<": "
                <<result<<endl;
        }
    }
    */

    return 0;
}

long long factorial(long long n)
{
    if(n==0 || n==1) return 1;
    else return n*factorial(n-1);
}

int getinfo(Student pa[],int n)
{
    cout<<"Max "<<n<<" entities.\n"
        <<"you can enter a blank line to terminate"
        <<" the input in advance\n";

    for(int i = 0;i<n;i++)
    {
        cout<<"Please input #"<<i+1<<" entity:\n";
        cout<<"Name: ";
        cin.getline(pa[i].fullname,SLEN);
        if(pa[i].fullname[0] == '\0')
        {
            cout<<"\n\nTerminate in advance.\n";
            return i;
        }

        cout<<"Hobby: ";
        cin.getline(pa[i].hobby,SLEN);
        cout<<"Ooplevel: ";
        cin>>pa[i].ooplevel;
        cin.get();
    }

    return n;
}

void display1(Student st)
{
    cout<<"Full Name: "<<st.fullname<<endl;
    cout<<"Hobby: "<<st.hobby<<endl;
    cout<<"Oop Level: "<<st.ooplevel<<endl;
}

void display2(const Student *st)
{
    cout<<"Full Name: "<<st->fullname<<endl;
    cout<<"Hobby: "<<st->hobby<<endl;
    cout<<"Oop Level: "<<st->ooplevel<<endl;
}

void display3(const Student pa[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<"Full Name: "<<pa[i].fullname<<endl;
        cout<<"Hobby: "<<pa[i].hobby<<endl;
        cout<<"Oop Level: "<<pa[i].ooplevel<<endl;
    }
}

double calculate(double x1,double x2,f_ptr fp)
{
    return fp(x1,x2);      //also work (*fp)(x1,x2);
}

double add(double x1,double x2)
{
    return x1+x2;
}

double multiple(double x1,double x2)
{
    return x1*x2;
}

double sub(double x1,double x2)
{
    return x1-x2;
}
