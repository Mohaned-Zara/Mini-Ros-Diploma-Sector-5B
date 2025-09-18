#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#define PI 3.14159265359
using namespace std;

class Circle{
    private:
        double radius;
    public:
//defualt ctor. & initialization list
        Circle():radius(0){
            cout<<"default ctor called"<<endl;
        }
        
        Circle(double r):radius(r){
            // cout<<"Only the name was taken"<<endl;
        }

//getter
        double getArea(){
            cout<<"Area: "<<endl;
            return radius*radius*PI;
        }
        double getCirc(){
            cout<<"Circ: "<<endl;
            return 2*PI*radius;    
        }
//~dtor
        ~Circle(){
            cout<<"destructor called"<<endl;
        }

};


int main(){
    double r1;
    cout<<"enter radius: ";
    cin>>r1;
    Circle c1{r1};

    cout<<c1.getArea()<<endl;
    cout<<c1.getCirc()<<endl;


    return 0;
}