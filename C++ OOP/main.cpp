#include <iostream>
#include <cstring>
#include "src/Car.cpp"
#include "src/Customer.cpp"
#include "headers/Garage.h"
#include "src/Garage.cpp"

int main() {
    std::string features = "Bluetooth, heated seats, parking sensors, 360 camera";
    Car myCar("BMW", "M5", "Sedan", "ZF8HP", 2022, features, 500, 600, 5, 50000, 300);
    Car myCar2("Toyota", "Supra", "Coupe", "Manual transmission", 2003, features, 300, 320, 3, 20000, 200);
    Car myCar3 = myCar2;
    Car myCar4 = myCar;
    Garage g;
    std::cout << "size of car class: " << sizeof(myCar);
    g.addCar(myCar);
    g.addCar(myCar2);
    g.addCar(myCar3);
    g.addCar(myCar4);
    g.removeCar(myCar4);
    //myCar.setFuelEfficiency(5);
    //std::cout << "Range before drive: " << myCar.getRange() << std::endl;
    //myCar.printInfoCar();
    Customer c;
    c.setBudget(100000);
    //c.purchaseCar(myCar);
    //c.purchaseCar(myCar);
    std:: cout << "Budget after buying car: " << c.getBudget();
    std::cout << "\n";
    //myCar.searchByAttribute();
    myCar.checkCarsInStock();
    g.getTotalCars();
    //myCar2.searchByAttribute();
    //myCar.setFuelTank(60);
    //myCar.refuel();
    //std::cout << myCar.getFuelTank();
    //myCar.startEngine();
    //myCar.drive(500);
    
    return 0;
}
