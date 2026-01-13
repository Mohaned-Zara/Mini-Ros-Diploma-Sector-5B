#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#define PI 3.14159265359
using namespace std;

class Animal{
    virtual void make_sound()=0;
};

class dog:public Animal{
    public:
        void make_sound(){
            cout<<"Woof Woof"<<endl;
        }
};
class cat:public Animal{
    public:
        void make_sound(){
            cout<<"Meow"<<endl;
        }
};
class bird:public Animal{
    public:
        void make_sound(){
            cout<<"Tweet Tweet!"<<endl;
        }
};

int main(){
    dog d;
    d.make_sound();
    cat c;
    c.make_sound();
    bird b;
    b.make_sound();

    return 0;
}