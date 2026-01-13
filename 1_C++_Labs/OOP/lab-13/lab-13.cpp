#include <iostream>
#include <string>
#include <cstring>
#define pi 3.14159265359

using namespace std;

class Shape{
    public:
        virtual double area()=0; //pure virtual fun
        virtual ~Shape(){};
};

class Circle : public Shape{
    protected:
        double diamter;
    public:
        //constructor
        Circle(double di):diamter(di){}
        // function override
        double area()override{
            return (pi/4)*diamter*diamter; 
        }
        ~Circle(){}
    };
    
    class Rectangle : public Shape{
        protected:
        double length,width;
        public:
        //ctor
        Rectangle(double le,double wi):length(le),width(wi){}
        double area()override{
            return length*width;
        }
        ~Rectangle(){}
        
};

int main(){
    short int num;
    double l,w,d;
    
    while (true)
{
    cout<<"\nchoose shape to calculate its area:\n0- Cancel \n1- Rectangle\n2-Circle\n"<<endl;
    cin>>num;
    if (num ==0)
        break;
    if (num==1)
    {
        cout<<"enter the length and width in order"<<endl;
        cin>>l;
        cin>>w;
        // Create Shape pointers
        Shape *ptr_R=new Rectangle(l,w);
         // Calculate and print areas
        cout<<"the area is= "<<ptr_R->area()<<endl; 
        delete ptr_R; //free memory
    }else if (num==2)
    {
        cout<<"enter the Diameter"<<endl;
        cin>>d;
        Shape *ptr_C=new Circle(d);
        cout<<"the area is= "<<ptr_C->area()<<endl;
        delete ptr_C; //free memory
    }else{
        cout<<"Wrong Number!!!"<<endl;
    }

}


    return 0;
}