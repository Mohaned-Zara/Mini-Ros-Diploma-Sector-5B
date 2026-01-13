#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#define pi 3.14159265359
using namespace std;

class Person{
    protected:
        string name,country,gender;
        int id,age;
    public:
        //defaut ctor
        Person():name("UnKnown"),country("UnKnown"),gender("UnKnown"),id(0),age(0){}

        //overload ctor
          Person(string n, int i, int a, string g, string c)
        : name(n), id(i), age(a), gender(g), country(c) {}

        //setter
        void setPersonData(string n, int i, int a, string g, string c) {
            name = n;
            id = i;
            age = a;
            gender = g;
            country = c;
        }

        //display
    void displayPersonData() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Country: " << country << endl;
    }
};


class Employee : public Person{
    protected:
        string job_title;
        double salary;

    public:
        //default ctor
        Employee():Person(),job_title("UNknown"),salary(0.0){

        }

        //overload ctor
        Employee(string n, int i, int a, string g, string c, string job, double sal)
        : Person(n, i, a, g, c), job_title(job), salary(sal) {}

        //setter
        void setEmployeeData(string n, int i, int a, string g, string c,string jt,double sal){
            setPersonData(n,i,a,g,c);
            job_title=jt;
            salary=sal;
        }
        //just in cas of U just passed the employee data
        void setEmployeeData(string jt,double sal){
            job_title=jt;
            salary=sal;
        }

        //display
        void dispalyEmployeeDate(){
            //display person data
            displayPersonData();
            //display employee data
        cout << "Job Title: " << job_title << endl;
        cout << "Salary: " << salary << endl;

        }
};


class Student : public Person{
    protected:
        string course;
        double fees;
    public:
        void setStudentData(string n, int i, int a, string g, string c,string co, double f){
            setPersonData(n,i,a,g,c);
            course = co;
            fees = f;
        }
    void displayStudentData() const {

        cout << "Course: " << course << endl;
        cout << "Fees: " << fees << endl;
        displayPersonData();
    }

};


int main(){

        // Using default constructor + setter functions
    Employee e1;
    e1.setPersonData("Ali", 101, 25, "Male", "Egypt");
    e1.setEmployeeData("Engineer", 5000);
    cout << "Employee 1 Data:" << endl;
    e1.dispalyEmployeeDate();

    cout << "--------------------" << endl;

    // Using overloaded constructor
    Employee e2("Sara", 102, 30, "Female", "UAE", "Manager", 1000.0);
    cout << "Employee 2 Data:" << endl;
    e2.dispalyEmployeeDate();
    cout << "--------------------" << endl;

    Employee e3;
    e3.dispalyEmployeeDate();
    cout<<"the default call"<<endl;
    cout<<"----------------------------"<<endl;
    e3.setEmployeeData("zara",455474571,20,"Male","Egy","engineer",5000.5);
    e3.dispalyEmployeeDate();


    return 0;
}
