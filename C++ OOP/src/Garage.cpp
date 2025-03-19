#pragma once
#include "../headers/Garage.h"
#include <iostream>

void Garage::getAvailableTotalStock(){
    std::cout << "Total cars in stock: " << this->currentCarCount << std::endl;
}
