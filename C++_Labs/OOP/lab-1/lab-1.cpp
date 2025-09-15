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
        //defualt ctor.
        Dog():name("Uknown"),age(0){
            cout<<"default ctor called"<<endl;
        }
        //~dtor
        ~Dog(){
            cout<<"destructor called"<<endl;
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
d1.getAge();
d1.getName();
cout<<"---------"<<endl;
d1.setAge(20);
d1.setName("abosalama");
d1.getAge();
d1.getName();






    return 0;
}