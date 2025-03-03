#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <sstream>

#define nl "\n"
#define spc << ' ' << ""
#define all(x) (x).begin(), (x).end()
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));

using namespace std;

class Person
{
protected:
    string name;
    int ID;

public:
    Person(string nam, int id) : name(nam), ID(id) {}

    virtual void displayInfo()
    {
        cout << "Name: " << name << " | ID: " << ID << endl;
    }

    virtual void getData(string &nam, int &id, set<string> &course) = 0;

    string getName() const { return name; }
    int getID() const { return ID; }
};

class Instructor : public Person
{
private:
    set<string> coursesTeaching;

public:
    Instructor(string nam, int id) : Person(nam, id) {}

    void addCourse(string course)
    {
        coursesTeaching.insert(course);
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Courses Teaching: ";
        for (const auto &c : coursesTeaching)
            cout << "\t" << c << "\n";
        cout << endl;
    }

    void getData(string &nam, int &id, set<string> &course) override
    {
        nam = name;
        id = ID;
        course = coursesTeaching;
    }
};

class Student : public Person
{
private:
    set<string> enrolledCourses;

public:
    Student(string nam, int id) : Person(nam, id) {}

    void addCourse(string course)
    {
        enrolledCourses.insert(course);
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Courses Enrolled: ";
        for (const auto &c : enrolledCourses)
            cout << "\t" << c << "\n";
        cout << endl;
    }

    void getData(string &nam, int &id, set<string> &course) override
    {
        nam = name;
        id = ID;
        course = enrolledCourses;
    }
};

class courseManager
{
private:
    map<string, string> courses;

public:
    void addCourse(string code, string name)
    {

        if (courses.find(code) == courses.end())
        {
            courses[code] = name;
            cout << "Course added successfully!" << endl;
        }
        else
        {
            cout << "Course already exista!" << endl;
        }
    }

    void enrollStudent(Student *stu, string code)
    {
        if (courses.find(code) != courses.end())
        {
            stu->addCourse(courses[code]);
            cout << "Student enrolled successfully!" << endl;
        }
        else
        {
            cout << "Invalid course code!" << endl;
        }
    }

    void assignInstructor(Instructor *ins, string code)
    {
        if (courses.find(code) != courses.end())
        {
            ins->addCourse(courses[code]);
            cout << "Instructor assigned successfully!" << endl;
        }
        else
        {
            cout << "Invalid course code!" << endl;
        }
    }

    void displayData(vector<Student *> &stu, vector<Instructor *> &ins)
    {
        cout << "\nCourses:" << endl;
        for (const auto &c : courses)
            cout << "Code: " << c.first << ", Name: " << c.second << endl;

        cout << "\nStudents:" << endl;
        for (const auto &s : stu)
            s->displayInfo();

        cout << "\nInstructors:" << endl;
        for (const auto &i : ins)
            i->displayInfo();

        cout << endl;
    }

    void saveData(vector<Student *> &stu, vector<Instructor *> &ins, courseManager &cm)
    {
        ofstream studentFile("students.txt"), instructorFile("instructors.txt"), courseFile("courses.txt");

        if (!studentFile || !instructorFile || !courseFile)
        {
            cout << "Error opening files for saving!" << endl;
            return;
        }

        // Save students
        for (const auto &s : stu)
        {
            string name;
            int id;
            set<string> courses;
            s->getData(name, id, courses);
            studentFile << name << "," << id;
            for (const auto &c : courses)
                studentFile << "," << c;
            studentFile << endl;
        }

        // Save instructors
        for (const auto &i : ins)
        {
            string name;
            int id;
            set<string> courses;
            i->getData(name, id, courses);
            instructorFile << name << "," << id;
            for (const auto &c : courses)
                instructorFile << "," << c;
            instructorFile << endl;
        }

        // Save courses
        for (const auto &c : courses)
        {
            courseFile << c.first << "," << c.second << endl;
        }

        cout << "Data saved successfully!" << endl;
    }

    void loadData(vector<Student *> &stu, vector<Instructor *> &ins, courseManager &cm)
    {
        ifstream studentFile("students.txt"), instructorFile("instructors.txt"), courseFile("courses.txt");
        string line, name, course, courseCode;
        int id;

        if (!studentFile || !instructorFile || !courseFile)
        {
            cout << "Error opening files for loading!" << endl;
            return;
        }

        stu.clear();
        ins.clear();

        // Load students
        while (getline(studentFile, line))
        {
            stringstream ss(line);
            getline(ss, name, ',');
            ss >> id;
            Student *s = new Student(name, id);
            while (getline(ss, course, ','))
                s->addCourse(course);
            stu.push_back(s);
        }

        // Load instructors
        while (getline(instructorFile, line))
        {
            stringstream ss(line);
            getline(ss, name, ',');
            ss >> id;
            Instructor *i = new Instructor(name, id);
            while (getline(ss, course, ','))
                i->addCourse(course);
            ins.push_back(i);
        }

        // Load courses
        while (getline(courseFile, line))
        {
            stringstream ss(line);
            getline(ss, courseCode, ',');
            getline(ss, course);
            cm.addCourse(courseCode, course);
        }

        cout << "Data loaded successfully!" << endl;
    }
};

int main()
{
    vector<Instructor *> instructors;
    vector<Student *> students;
    courseManager cm;
    int op = 0;

    while (op != 7)
    {
        cout << "\n1. Add Course\n2. Enroll Student\n3. Assign Instructor\n4. Display Data\n5. Save Data\n6. Load Data\n7. Exit\nEnter your choice: ";
        cin >> op;
        cin.ignore();

        if (op == 1)
        {
            string code, name;
            cout << "Enter course code: ";
            cin >> code;
            cin.ignore();
            cout << "Enter course name: ";
            getline(cin, name);
            cm.addCourse(code, name);
        }

        else if (op == 2)
        {
            string name, courseCode;
            int id;
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter course code: ";
            cin >> courseCode;
            bool exts=false;
            for (auto &&i : students)
            {
                if(i->getID() == id){
                    exts= true;
                    cm.enrollStudent(i, courseCode);
                }
            }
            if(!exts){
                Student *s = new Student(name, id);
                cm.enrollStudent(s, courseCode);
                students.push_back(s);
            }
            
            
        }

        else if (op == 3)
        {
            string name, courseCode;
            int id;
            cout << "Enter instructor name: ";
            getline(cin, name);
            cout << "Enter instructor ID: ";
            cin >> id;
            cout << "Enter course code: ";
            cin >> courseCode;
            bool exts;
            for (auto &&i : instructors)
            {
                if(i->getID() == id){
                    exts= true;
                    cm.assignInstructor(i, courseCode);
                }
            }
            if(!exts){
                Instructor *i = new Instructor(name, id);
                cm.assignInstructor(i, courseCode);
                instructors.push_back(i);
            }
            
        }

        else if (op == 4)
        {
            cm.displayData(students, instructors);
        }

        else if (op == 5)
        {
            cm.saveData(students, instructors, cm);
        }

        else if (op == 6)
        {
            cm.loadData(students, instructors, cm);
        }

        else if (op == 7)
        {
            cout << "Exiting program..." << endl;
        }

        else
        {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    for (auto s : students)
        delete s;
    for (auto i : instructors)
        delete i;

    return 0;
}