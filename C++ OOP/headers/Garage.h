#pragma once
#include <iostream>
#include "Car.h"

class Garage{
private:
    std::string car = "";
    int capacity = 0;
    static int totalCars;

public:
    Garage(){};

    //getters
    std::string getCar() const{
        return this->car;
    }

    int getCapacity() const{
        return this->capacity;
    }


    //setters
    void setCapacity(int newCapacity){
        if(newCapacity < 0)
            throw "Capacity cannot be negative.";
        this->capacity = newCapacity;
    }

    //methods
    void getAvailableTotalStock();
    void addCar(const Car& car);
    void removeCar(const Car& car);
    static int getTotalCars();
};