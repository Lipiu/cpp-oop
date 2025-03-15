#include <iostream>
#include "../headers/Customer.h"
#include "../headers/Car.h"

// Print info
void Customer::printInfoCustomer(){
    std::cout << "First name: " << this->firstName << std::endl;
    std::cout << "Last name: " << this->lastName << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Budget: " << this->budget << std::endl;
}

// Purchase car
void Customer::purchaseCar(Car& car){

    if(this->budget < car.getPrice())
        std::cout << "Insufficient funds.";
    else if(car.getCarsInStock() <= 0)
        std::cout << "The car is out of stock!";
    else{
        std::cout << "Purchase successful. You bought: " << car.getManufacturer() << " " << car.getModel() << std::endl; 
        carPurchased++;
        car.decreaseStock();
    }
}
