#pragma once
#include "../headers/Garage.h"
#include <iostream>

int Garage::totalCars = 0;

void Garage::addCar(const Car& car){
    totalCars++;
}

int Garage::getTotalCars(){
    std::cout << "Total cars " << totalCars << std::endl;
    return 0;
}
