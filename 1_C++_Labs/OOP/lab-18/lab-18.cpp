#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
class Person;
class Dog{
    public:
        string name;
        weak_ptr<Person>owner; //! weak_ptr to the Dog obj
        
        Dog(const string& n) : name(n) {
            cout << "Dog created: " << name << endl;
        }

        ~Dog() {
            cout << "Dog destroyed: " << name << endl;
        }
};

class Person{
    public:
        string name;
        shared_ptr<Dog>dog; //! shared_ptr to the Person obj

        Person(const string& n):name(n){
            cout << "Person created: " << name << endl;
        };

        ~Person() {
        cout << "Person destroyed: " << name << endl;
        }   
};



int main(){

    shared_ptr<Person>p1= make_shared<Person>("Mohaned");        //* shared_ptr to person obj
    shared_ptr<Dog>d1 = make_shared<Dog> ("Rex");               //* shared_ptr to dog obj

    //assign the (shared_ptr to dog obj) TO (shared_ptr) to (the Person obj).
    p1->dog = d1; 
    //assign the ( -shared_ptr- to -the Person obj- ) to ( weak_ptr of the Dog obj ).
    d1->owner = p1;
    
    return 0;
}