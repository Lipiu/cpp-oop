#pragma once
#include <iostream>
#include "Car.h"

class Garage{
private:
    std::string car = "";
    static int totalCars;

public:
    Garage(){};

    //getters
    std::string getCar() const{
        return this->car;
    }


    //methods
    void addCar(const Car& car);
    void removeCar(const Car& car);
    static int getTotalCars();
};