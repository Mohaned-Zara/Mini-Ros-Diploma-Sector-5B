#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Person{
    protected:
        string name;
    public:
        //defaut ctor
        Person():name("UnKnown"){}
        //overload ctor
        Person(string n):name(n){}
        
        //setter
        void setPersonData(string n) {
            name = n;
        }

        //getter
        string getName(){
            return name;
        }

        //display
    void displayPersonData(){
        cout << "Name: " << name << endl;
    }
};


class Student : virtual public Person{
    protected:
        int std_id;
    public:
        //default ctor
        Student(): Person(),std_id(0){}

        //overload ctor
        Student(string n, int i): Person(n),std_id(i){}

        //setter
        void setStudentData(int i){
            std_id=i;
        }
        void setStudentData(string n,int i){
            setPersonData(n);
            std_id=i;
        }
        
        //getter
        int getStudentID(){
            return std_id;
        }
        
        //display
        void displayStudentDate(){
            //display person data
            displayPersonData();
            //display Student data
            cout << "Student ID: " << std_id << endl;
            
        }
    };
    
    
    class Teacher : virtual public Person{
        protected:
        int tchr_id;
        public:
        //default ctor
        Teacher():Person(),tchr_id(0){}
        
        //overload ctor
        Teacher(string n,int ti):Person(n),tchr_id(ti){
        }
        
        //setter
        void setTeacherData(int ti){
            tchr_id=ti;
        }
        void setTeacherData(string n,int ti){
            setPersonData(n);
            tchr_id=ti;
        }
        
        //getter
        int getTeacherID(){
            return tchr_id;
        }
        
        //display
        void displayTeacherDate(){
            //display person data
            displayPersonData();
            //display Teacher data
            cout << "Teacher ID: " << tchr_id << endl;
            
        }
        
        
    };
    
    class TeachingAssistant : public Student , public Teacher{
        protected:
        string course;
        public:
        //default ctor
        TeachingAssistant():Person(),Student(),Teacher(),course(""){}
        
        //overload ctor
        TeachingAssistant(string n,int si,int ti,string c)
        :Person(n),Student(n,si),Teacher(n,ti),course(c){}

        //setter
        void setCourse(string c){
            course=c;
        }

        void setCourse(string n,int si, int ti,string c){
            setPersonData(n);
            setStudentData(si);
            setTeacherData(ti);
            course=c;
        }

        //getter
        string getCourse(){
            return course;
        }

        void displayTAData() {
            displayPersonData();
            displayStudentDate();
            displayTeacherDate();
            cout << "Course: " << course << endl;
        }

};


int main(){
    Person p1;
    cout<<p1.getName()<<endl;
    p1.setPersonData("zara");

    Student s1,s2;
    s1.setStudentData(2104);
    cout<<s1.getName()<<endl;
    cout<<s1.getStudentID()<<endl;
cout<<""""""""""""""<<endl;
    s2.setStudentData("mona",4547);
    cout<<s1.getName()<<endl;
    cout<<s1.getStudentID()<<endl;
Teacher t1,t2;
t1.setTeacherData(8092);
t2.setTeacherData("professor",90751);

TeachingAssistant ta1,ta2;


    return 0;
}
