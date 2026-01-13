#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#define pi 3.14159265359
using namespace std;

class Vehcile{
    protected:
        string brand;
    public:
        //defaut ctor
        Vehcile():brand("UnKnown"){}

        //setter
        void setVehcileData(string b) {
            brand = b;
        }

        //display
    void displayVehcileData() const {
        cout << "brand: " << brand << endl;
    }


};


class Car : public Vehcile{
    protected:
        int num_doors;

    public:
        //default ctor
        Car():Vehcile(),num_doors(0){}

        //overload ctor
        void setCarData(string b,int d){
            setVehcileData(b);
            num_doors=d;
        }
        
        //setter
        void setCarData(int d){
            num_doors=d;
        }

        //display
        void dispalyCarDate()const{
            //display person data
            displayVehcileData();
            //display employee data
        cout << "Numbers of doors: " << num_doors << endl;

        }
};


class SportCar : public Car{
    protected:
        bool conversion;
    public:
        //default ctor
        SportCar():Car(),conversion(false){}

        //setter
        void setSportCarData(string b,int d,bool con){
            setCarData(b,d);
            conversion=con;
        }


        //just pass one parameter
        void setSportCarData(bool con){
            conversion=con;
        }

    void displaySportCarData() const {
        //display car
        dispalyCarDate();
        cout << "the status of conversion: " << conversion << endl;
    }

};


int main(){

    //vechile
    Vehcile v1;
    //default ctor
    v1.displayVehcileData();
    cout<<"default Vehcile ctor called"<<endl;
    cout<<"--------------------"<<endl;
    //setter
    v1.setVehcileData("BMW");
    v1.displayVehcileData();
    cout<<"setter method called"<<endl;
    cout<<"--------------------"<<endl;
    
    //car
    Car c1;
    //defualt ctor
    c1.dispalyCarDate();
    cout<<"default Car ctor called"<<endl;
    cout<<"--------------------"<<endl;
    // setter
    c1.setCarData(2);
    c1.dispalyCarDate();
    cout<<"setter Car method called"<<endl;
    cout<<"--------------------"<<endl;
    //overload ctor
    c1.setCarData("Mercedes",4);
    c1.dispalyCarDate();
    cout<<"overload Car ctor called"<<endl;
    cout<<"--------------------"<<endl;
    
    //sportcar
    SportCar sc1;
    //default ctor
    sc1.displaySportCarData();
    cout<<"default SportCar ctor called"<<endl;
    cout<<"******************"<<endl;
    //setter
    sc1.setSportCarData(true);
    sc1.displaySportCarData();
    cout<<"setter SportCar method called"<<endl;
    cout<<"--------------------"<<endl;
    //overloading ctor
    sc1.setSportCarData("Toyota",2,true);
    sc1.displaySportCarData();
    cout<<"overload SportCar ctor called"<<endl;
    cout<<"--------------------"<<endl;
    
    

    return 0;
}
