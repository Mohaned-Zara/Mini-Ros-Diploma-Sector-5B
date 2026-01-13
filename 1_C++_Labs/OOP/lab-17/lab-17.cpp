#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Car{
    protected:
        string brand, model;
    public:
        Car(string b,string m):brand(b),model(m){};
        void display(){
            cout<<"the brand is: "<<brand<<endl;
            cout<<"the model is: "<<model<<endl;
        }
};

int main(){
    shared_ptr<Car>c1(new Car("BMW","C9"));
    shared_ptr<Car>c2(c1);
    
    //? in modern c++14
    //? shared_ptr<Car>p=make_shared<Car>("BMW","C9");

    c1->display();
    cout<<"the second ptr"<<endl;
    c2->display();
    cout<<"the reference counts are: "<<c2.use_count()<<endl;

    if (!c1) {
        cout << "p1 is now null after moving ownership!" << endl;
    }


    return 0;
}