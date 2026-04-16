#include<iostream>
#include<string>

using namespace std;

// Real life car 
// class Car{
//     public:
//         virtual void startEngine() = 0;
//         virtual void shiftGear(int gear) = 0;
//         virtual void accelerate() = 0;
//         virtual void brake() = 0;
//         virtual void stopEngine() = 0;
//         virtual ~Car(){};
// };

class SportsCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
        string tyre;


    public:
        SportsCar(string b, string m){
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            tyre = "MRF";
        }

        // getters and setters
        int getCurrentSpedd(){
            return this->currentSpeed;
        }
        string getTyre(){
            return this->tyre;
        }

        void setTyre(string type){
             
            this->tyre = tyre;
        }

        void startEngine(){
            isEngineOn = true;
            cout<<brand<<" "<<model<<": Engine starts with a roar!"<<endl;
        }

        void shiftGear(int gear){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" : Engine is off ! Cannot Shift Gear."<<endl;
                return ;
            }
            currentGear = gear;
            cout<<brand<<" "<<model<<" :Shifted to gear "<<currentGear<<endl; 
        }
        
        void accelerate(){
            if(!isEngineOn){    
                cout<<brand<<" "<<model<<" : Engine is off ! Cannot accelerate."<<endl;
                return;
            }
            currentSpeed += 20;
            cout<<brand<<" "<<model<<" : Accelerating to "<<currentSpeed<<"km/h"<<endl;
        }

        void brake(){
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Breaking Speed is now "<<currentSpeed<<"km/h"<<endl;
        }
        
        void stopEngine(){
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout<<brand<<" "<<model<<" : Enigne turend off."<<endl;
        }
};

int main(){

    SportsCar* myCar = new SportsCar("Ford", "Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    // myCar->currentSpeed = 500 ;

    // cout<<"Current Speed if My Sports Car is set to "<<myCar->currentSpeed<<endl;
    cout<<myCar->getCurrentSpedd();

    delete myCar;

    return 0;
}