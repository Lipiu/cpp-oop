#include <iostream>
#include <cstring>
#include "src/Car.cpp"

int main() {
    char* features[] = { (char*)"Sunroof", (char*)"Leather Seats", (char*)"Bluetooth" };
    
    Car myCar("Toyota", "Supra", 2022, features, 12.5, 382, 368, 5, 50000, 250, 100);
    // myCar.printInfo();
    // myCar.checkCarsInStock();
    myCar.startEngine();

    return 0;
}
