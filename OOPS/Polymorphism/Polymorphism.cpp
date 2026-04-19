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
        
        virtual void accelerate() = 0; // Abstract method for Dynamic Polymorphism
        virtual void Brake() = 0; // Abstract method for Dynamic Polymorphism
        virtual ~Car(){} // Virtual destructor 
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

        // Overriding accelerate - Dynamic Polymorphism
        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<" : Cannot accelerated! Enigne id off."<<endl;
            }
            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accekerating to "<< currentSpeed<<" km/h"<<endl;
        }
        // overriding brake - Dynamic Polymorphism
        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Braking Speed is now "<<currentSpeed<<" km/h"<<endl;
        }
};

class ElectricCar:public Car{
    private:
        int batteryLevel;
    public:
        ElectricCar(string b, string m):Car(b,m){
            this->batteryLevel = 100;
        }
        // specific method for Electric Car
        void chargeBattery(){
            batteryLevel = 100;
            cout<<brand<<" "<<model<<": Battery fully charged!"<<endl;
        }

        // Overriding accelerate - Dynamic Polymorphism
        void accelerate(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" : Cannot accelerated! Engine id off."<<endl;
                return;
            }
            if(batteryLevel <=0 ){
                cout<<brand<<" "<<model<<" : Battery dead! Cannot accelerate."<<endl;
                return;
            }
            batteryLevel -= 10;
            currentSpeed += 15;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<< "km/h. BAttery at "<<batteryLevel<<"%."<<endl;
        }

        // Overriding brake - Dynamic Polymorphism
        void brake(){
            currentSpeed -= 15;
            if(currentSpeed < 0) currentSpeed = 0;
            cout<<brand<<" "<<model<<" :Regenerative Speed is now "<< currentSpeed<<" km/h. Battery % "<<batteryLevel<<endl;

        }
};

int main(){

    Car* myManualCar = new ManualCar("Suzuki","WagonR");
    myManualCar->startEngine();
    // myManualCar->shiftGear(2);
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"----------------------"<<endl;

    Car* myElectricCar = new ElectricCar("Tesla","Model S");
    // myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate();
    // myElectricCar->brake();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;
return 0;
}