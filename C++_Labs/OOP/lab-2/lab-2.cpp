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

        //initialization ctor
        Dog(string n,int a):name(n),age(a){
            cout<<"initialization ctor"<<endl;
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
//init. ctor
Dog d2{"zara",10};
d2.getAge();
d2.getName();
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