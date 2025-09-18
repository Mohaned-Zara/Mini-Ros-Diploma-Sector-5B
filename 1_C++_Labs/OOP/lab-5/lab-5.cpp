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
        static int counter;
        // //defualt ctor.
        // Dog():name("Uknown"),age(0){
        //     cout<<"default ctor called"<<endl;
            
        // }
        // //~dtor
        // ~Dog(){
        //     cout<<"destructor called"<<endl;
        // }


        //counter fun
        Dog(){
            counter++;
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

int Dog :: counter= 0;


int main(){
    cout<<Dog :: counter<<endl;
    Dog d1,d2,d3,d4;
    cout<<Dog :: counter<<endl;




    return 0;
}