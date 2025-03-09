#include <iostream>
#include <cstring>
#include "src/Car.cpp"

int main() {
    Car c;
    Car c1 = c;
    c.printInfo();
    c.checkCarsInStock();
    
}
