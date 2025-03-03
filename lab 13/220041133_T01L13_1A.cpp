#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

#define nl "\n"
#define spc << ' ' << ""
#define all(x) (x).begin(), (x).end()
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
typedef long long ll;
typedef std::vector<ll> llvec;
using namespace std;




class Person
{
protected:
    string name;
    int ID;

public:
    Person(string nam, int id)
        : name(nam), ID(id)
    {
    }

    void getInfo(string name, int id)
    {
        name = Person::name;
        id = ID;
        return;
    }

    virtual void displayInfo()
    {
        cout << "Name : " << name << " bearing ID : " << ID << endl;
        return;
    }

    virtual void getData(string nam, int id, set<string> course) {};

    // end of public
};



class Instructor : public Person
{

private:
    set<string> coursesTeaching;

public:
    void addCourse(string str)
    {
        coursesTeaching.insert(str);
        return;
    }

    void displayInfo() override
    {

        Person::displayInfo();
        cout << "Teaching: " << endl;
        for (auto &&i : coursesTeaching)
        {
            cout << "\t" << i << endl;
        }
    }

    void getData(string nam, int id, set<string> course) override
    {
        nam = name;
        id = ID;
        course = coursesTeaching;
    };

    // end of public
};



class Student : public Person
{
private:
    set<string> enrolledCourses;

public:
    void addCourse(string str)
    {
        enrolledCourses.insert(str);
        return;
    }

    void displayInfo() override
    {

        Person::displayInfo();
        cout << "Enrolled in: " << endl;
        for (auto &&i : enrolledCourses)
        {
            cout << "\t" << i << endl;
        }
    }

    void getData(string nam, int id, set<string> course) override
    {
        nam = name;
        id = ID;
        course = enrolledCourses;
    };

    // end of public
};


class courseManager
{

private:
    map<string, string> courses;

public:
    void addCourse(string name, string code)
    {
        courses[code] = name;
    }

    void enrollStudent(Student* stu, string code)
    {

        if (courses.find(code) != courses.end())
        {
            stu->addCourse(courses[code]);
        }
        else
        {
            cout << "Invalid course code entered, please try again" << endl;
        }
        return;
    }

    void assignInstructor(Instructor ins, string code)
    {

        if (courses.find(code) != courses.end())
        {
            ins.addCourse(courses[code]);
        }
        else
        {
            cout << "Invalid course code entered, please try again" << endl;
        }
        return;
    }

    void DisplayData()
    {
        cout << "Courses: " << endl;
        for (auto &&i : courses)
        {
            cout << "Code: " << i.first << "Name: " << i.second << endl;
        }
        return;
    }

    // end of public
};



void saveData(vector<Person*> p, int type)
{

    if (type == 1)
    {
        ofstream outFIle("students.txt", ios::out);
        for (auto &&i : p)
        {
            string name;
            int id;
            set<string> courses;
            i->getData(name, id, courses);

            outFIle << name << "," << id << ",";
            for (auto &&i : courses)
            {
                outFIle << i << ",";
            }
            outFIle << "\n";
        }
    }
    else if (type == 2)
    {

        ofstream outFIle("instructors.txt", ios::out);
        for (auto &&i : p)
        {
            string name;
            int id;
            set<string> courses;
            i->getData(name, id, courses);

            outFIle << name << "," << id << ",";
            for (auto &&i : courses)
            {
                outFIle << i << ",";
            }
            outFIle << "\n";
        }
    }
}



void loadData(Person p, int type)
{
}

int main()
{
    vector<Instructor*> ins;
    vector<Student*> stu;
    courseManager cors;
    
    int op = 0;
    while(op != -1){
        
    }

}