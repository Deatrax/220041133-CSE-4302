#include "133 task 2.h"


void Employee::setName(string nam){
    if (nam.length()<=2)
    {
        nam="John Doe";
        return;
    }
    
    name=nam;
}

void Employee::setDOB(DOB given){
    if (given.year>2002)
    {
        dob.date=2;
        dob.month=January;
        dob.year=2002;
        return;
    }
    
    dob=given;
}

void Employee::setSalary(int sal){
    if (sal<10000 || sal>100000)
    {
        salary=10000;
        return;
    }
    
    salary=sal;
}

string Employee::getName() const{
    return name;
}

DOB Employee::getDOB() const{
    return dob;
}

int Employee::getSalary() const{
    return salary;
}