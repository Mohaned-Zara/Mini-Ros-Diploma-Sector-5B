#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#define pi 3.14159265359
using namespace std;
class integer{
    private:
        int * ptr=nullptr;
    public:
    //defualt ctor
        integer(){
            ptr=new int(0);
            cout << "Default Constructor called\n";
        }
    //parametrized
    integer(int a){
        ptr=new int(a);
        cout << "Parameterized Constructor called\n";
    }
    //copy ctor
    integer(const integer &src){
           ptr=new int(*src.ptr);
           cout << "Copy Constructor called\n";

    }

integer& operator=(const integer&rhs){
    if (this ==&rhs)
    {
        return (*this);
    }
    delete ptr;
    ptr = new int(*rhs.ptr);
    cout << "Copy Assignment Operator called\n";
    return *this;
    
    
}
    //setter
    void set_value(int v){
        *ptr=v;
    }
    //getter
    int get_value()const{
        return *ptr;
    }
    //destructor
    ~integer(){
        delete ptr;
        cout << "Destructor called\n";
    }

};


int main(){
    integer num1; //default
    integer num2{20}; // parametrized

    num1=num2;
    num2.set_value(10);
    cout << "num1: " << num1.get_value() << endl;
    cout << "num2: " << num2.get_value() << endl;
    return 0;
}