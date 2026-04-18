#include<iostream>
#include<string>
using namespace std;

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    
    public:
        Car(string b, string m){
            this->model = m;
            this->brand = b;
            isEngineOn = false;
            currentSpeed = 0;
        }
        // common methods for all cars;
        void startEngine(){
            isEngineOn = true;
            cout<<brand<<" "<<model<<" :Engine Started."<<endl;
        }
        void stopEngine(){
            isEngineOn = false;
            currentSpeed += 20;
            cout<<brand<<" "<<model<<" :Engine turned off"<<endl;
        }
        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" :Cannot accekerated Engine id off."<<endl;
            }
        }

        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout<<brand<<" "<<model<<" :Braking! Speed is now "<<currentSpeed<<" km/h"<<endl;
        }
        virtual ~Car(){}
};
class ManualCar:public Car{
    // inherit from car
    private:
        int currentGear;// specific to Manual car
    public:
        ManualCar(string b, string m):Car(b,m){
            currentGear = 0;
        }
        // specific method form Manual car
        void shiftGear (int gear){
            currentGear = gear;
            cout<<brand<<" "<<model<<" :Shifted to gear "<<currentGear<<endl;
        }
};

class ElectricCar:public Car{
    private:
        int batteryLevel;
    public:
        ElectricCar(string b, string m):Car(b,m){
            batteryLevel = 100;
        }
        // specific method for Electric Car
        void chargeBattery(){
            batteryLevel = 100;
            cout<<brand<<" "<<model<<": Battery fully charged!"<<endl;
        }
};

int main(){

    ManualCar* myManualCar = new ManualCar("Suzuki","WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"----------------------"<<endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla","Model S");
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
return 0;
}