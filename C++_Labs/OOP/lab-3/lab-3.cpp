#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#define pi 3.14159265359
using namespace std;

class Dog{
    private:
        string name;
        int age;
    public:
        //defualt ctor. & initialization list
        Dog():name("Uknown"),age(0){
            cout<<"default ctor called"<<endl;
        }
        //~dtor
        ~Dog(){
            cout<<"destructor called"<<endl;
        }

        //take only the name
        Dog(string n):name(n),age(0){
            cout<<"Only the name was taken"<<endl;
        }
        //take only the age
        Dog(int a):name("Unknown"),age(a){
            cout<<"Only the age was taken"<<endl;
        }
        //take both
        Dog(string n,int a):name(n),age(a){
            cout<<"both the name and age were taken"<<endl;
        }


        //setter
        void setName(string n){
            
            name = n;
            cout<<"setName called"<<endl;
        }
        void setAge(int a){
            age = a;
            cout<<"setAge called"<<endl;

        }

        //getter
        string getName(){

            cout<<"getName called"<<endl;
            cout<< name<<endl;
            return name;
        }
        int getAge(){
            cout<<"getAge called"<<endl;
            cout<<age<<endl;
            return age;    
        }
};


int main(){

Dog d1;
//default ctor
d1.getAge();
d1.getName();
cout<<"---------"<<endl;

//Both name & age
Dog d2{"zara",10};
d2.getAge();
d2.getName();
cout<<"---------"<<endl;

//Name only
Dog d3{"Ahmed"};
d3.getName();
cout<<"---------"<<endl;

//Age only
Dog d4=20;
d4.getAge();
cout<<"---------"<<endl;

// old way d1
d1.setAge(20);
d1.setName("abosalama");
d1.getAge();
d1.getName();
cout<<"---------"<<endl;

// old way d2
d2.setAge(20);
d2.setName("abosalama");
d2.getAge();
d2.getName();
cout<<"---------"<<endl;






    return 0;
}