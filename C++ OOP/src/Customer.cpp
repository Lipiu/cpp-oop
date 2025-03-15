#include <iostream>
#include "../headers/Customer.h"

// print info
void Customer::printInfoCustomer(){
    std::cout << "First name: " << this->firstName << std::endl;
    std::cout << "Last name: " << this->lastName << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Budget: " << this->budget << std::endl;
}