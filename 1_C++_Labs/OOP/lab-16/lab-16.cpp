#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Rectangle{
    public:
    double width,height;
        Rectangle(double w,double h):width(w),height(h){};
        double area(){
            return width * height;
        }
};

int main(){
    unique_ptr<Rectangle>p1(new Rectangle(5,5));

    //in modern c++14
    unique_ptr<Rectangle>p=make_unique<Rectangle>(5,5);

    cout << "The area = " << p1->area() << endl;
    
    // unique_ptr<Rectangle>p2(p1); //error
    unique_ptr<Rectangle>p2=move(p1);

    if (!p1) {
        cout << "p1 is now null after moving ownership!" << endl;
    }


    return 0;
}