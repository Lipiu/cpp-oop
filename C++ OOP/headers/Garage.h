#include <iostream>
#include "Car.h"

class Garage{
private:
    std::string car = "";
    int capacity = 0;
    int currentCarCount = 0;

public:
    Garage(){};

    //getters
    std::string getCar() const{
        return this->car;
    }

    int getCapacity() const{
        return this->capacity;
    }

    int currentCarCount() const{
        return this->currentCarCount;
    }

    //setters
    void setCapacity(int newCapacity){
        if(newCapacity < 0)
            throw "Capacity cannot be negative.";
        this->capacity = newCapacity;
    }

    void setCurrentCarCount(int newCurrentCarCount){
        if(newCurrentCarCount < 0)
            throw "Car count cannot be negative.";
        this->currentCarCount = newCurrentCarCount;
    }

    //methods
    void addCar(const Car& car);
    void removeCar(const Car& car);
    std::string getAvailableCars();
    int getAvailableStock();
};