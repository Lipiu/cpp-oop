#include <iostream>
#include <cstring>
#include "src/Car.cpp"

int main() {
    char* features[] = { (char*)"Sunroof", (char*)"Leather Seats", (char*)"Bluetooth" };
    
    Car myCar("Toyota", "Supra", 2022, features, 12.5, 382, 368, 5, 50000, 250, 100, 70);
    myCar.setFuelEfficiency(5);
    std::cout << "Range before drive: " << myCar.getRange() << std::endl;
    myCar.printInfo();
    myCar.checkCarsInStock();
    myCar.setFuelTank(100);
    myCar.startEngine();
    myCar.drive(500);
    
    return 0;
}
