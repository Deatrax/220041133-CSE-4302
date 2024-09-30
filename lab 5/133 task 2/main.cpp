#include "133 task 2.h"


void setInfo(Employee& a){
    fflush(stdin);
    cout<<"Name:";
    string name;
    getline(cin, name);
    fflush(stdin);
    cout<<"Date of birth [int day, int month, int year] :";
    int mon;
    DOB inst;
    cin>>inst.date>>mon>>inst.year;
    inst.month=months(mon);
    cout<<"Give the salary: ";
    cin>>mon;
    a.setName(name);
    a.setDOB(inst);
    a.setSalary(mon);
    //cin>>a;
}

void getInfo(Employee& a){
    string nam=a.getName();
    DOB inst=a.getDOB();
    int sal=a.getSalary();

    cout<<"Name="<<nam<<" DOB="<<inst.date<<"-"<<inst.month+1<<"-"<<inst.year<<nl;
}
int main(){

    Employee emp[5];
    for (int i = 0; i < 5; i++)
    {
        setInfo(emp[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        getInfo(emp[i]);
    }
    
    
    
}