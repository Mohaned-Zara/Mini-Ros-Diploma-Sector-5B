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

        Student s1;
        s1.setStudentData("zara",455474571,20,"Male","Egy","math",200.0);
        s1.displayStudentData();


    return 0;
}
