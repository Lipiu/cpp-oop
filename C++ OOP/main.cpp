#include <iostream>
#include <cstring>
#include "src/Car.cpp"

int main() {
    char* features[] = { (char*)"Sunroof", (char*)"Leather Seats", (char*)"Bluetooth" };
    
    Car myCar("Toyota", "Supra", "Sedan", "6 speed manual", 2002, features, 400, 15, 320, 350, 4, 10000, 250);
    //myCar.setFuelEfficiency(5);
    //std::cout << "Range before drive: " << myCar.getRange() << std::endl;
    myCar.printInfo();
    //myCar.checkCarsInStock();
    //myCar.setFuelTank(60);
    //myCar.refuel();
    //std::cout << myCar.getFuelTank();
    //myCar.startEngine();
    myCar.drive(500);
    
    return 0;
}
