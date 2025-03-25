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
        std::cout << "Insufficient funds." << std::endl;
    else if(car.getCarsInStock() <= 0)
        std::cout << "The " << car.getManufacturer() << " " << car.getModel() <<  " is out of stock!" << std::endl;
    else{
        std::cout << "Purchase successful. You bought: " << car.getManufacturer() << " " << car.getModel() << std::endl; 
        carPurchased++;
        this->budget = this->budget - car.getPrice();
        car.decreaseStock();
    }
}

void Customer::addMoney(float amount){
    std::string answer;
    std::cout << "Would you like to add money to your budget? (yes/no): ";
    std::cin >> answer;

    for (int i = 0; i < answer.length(); i++) {
        answer[i] = tolower(answer[i]);
    }

    if (answer == "yes") {
        this->budget += amount;
        std::cout << "Updated budget: $" << this->budget << std::endl;
    } else if (answer == "no") {
        std::cout << "Budget remains: $" << this->budget << std::endl;
    } else {
        std::cout << "Invalid input, no action taken." << std::endl;
    }
}

