#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#define PI 3.14159265359
using namespace std;

class Rectangle{
    private:
        double length,width;
    public:
//defualt ctor. & initialization list
        Rectangle():length(0),width(0){
            cout<<"default ctor called"<<endl;
        }
        
        Rectangle(double l,double w):length(l),width(w){
            // cout<<"Only the name was taken"<<endl;
        }

//friend funs
        friend double getArea(const Rectangle &a);
        friend double getPerimeter(const Rectangle &p);
//~dtor
        ~Rectangle(){
            cout<<"destructor called"<<endl;
        }

};


//getter
        double getArea(const Rectangle &source){
            cout<<"Area: ";
            return source.length * source.width;
        }
        double getPerimeter(const Rectangle &source){
            cout<<"Perimeter: ";
            return 2*(source.length + source.width);    
        }


int main(){
    double l,w;
    cout<<"enter lenght: ";
    cin>>l;
    cout<<"enter width: ";
    cin>>w;
    Rectangle r1{l,w};

    cout<<getArea(r1)<<endl;
    cout<<getPerimeter(r1)<<endl;


    return 0;
}