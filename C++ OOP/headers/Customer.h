#pragma once
#include <iostream>
#include "Car.h"

class Customer{
private:
    int age = 0;
    std::string firstName = "";
    std::string lastName = "";
    std::string email = "";
    std::string phoneNumber = "";
    int customerID = 0;
    double budget = 0;
    static int carPurchased;
    
public:
    Customer(){};

    // constructor with parameters
    Customer(std::string firstName, std::string lastName, int age, std::string email, std::string phoneNumber){
        this->setFirstName(firstName);
        this->setLastName(lastName);
        this->setAge(age);
        this->setEmail(email);
        this->setPhoneNumber(phoneNumber);
    }

    // copy constructor
    Customer(const Customer& customer){
        firstName = customer.firstName;
        lastName = customer.lastName;
        age = customer.age;
        email = customer.email;
        phoneNumber = customer.phoneNumber;
    }

    // getters
    int getAge() const{
       return this->age; 
    }

    std::string getFirstName() const{
        return this->firstName;
    }

    std::string getLastName() const{
        return this->lastName;
    }

    std::string getEmail() const{
        return this->email;
    }

    std::string getPhoneNumber() const{
        return this->phoneNumber;
    }

    int getCustomerID() const{
        return this->customerID;
    }

    double getBudget() const{
        return this->budget;
    }

    //setters
    void setAge(int newAge){
        const int minAge = 18;
        if(newAge < minAge)
            throw std::invalid_argument ("You are too young to buy a car.");
        this->age = newAge;
    }

    void setFirstName(std::string newFirstName){
        if(newFirstName.empty())
            throw std::invalid_argument ("First name cannot be empty. Exiting...");
        this->firstName = newFirstName;
    }

    void setLastName(std::string newLastName){
        if(newLastName.empty())
            throw std::invalid_argument ("Last name cannot be empty. Exiting...");
        this->lastName = newLastName;
    }

    void setEmail(std::string newEmail){
        if(newEmail.empty() || newEmail.find('@') == std::string::npos)
            throw std::invalid_argument ("Invalid email format. Exiting...");
        this->email = newEmail;
    }

    void setPhoneNumber(std:: string newPhoneNumber){
        if(newPhoneNumber.empty())
            throw std::invalid_argument ("Phone number cannot be empty. Exiting...");
        this->phoneNumber = newPhoneNumber;
    }

    void setCustomerID(int newCustomerID){
        if(newCustomerID < 0)
            throw std::invalid_argument ("Customer ID cannot be negative. Exiting...");
        this->customerID = newCustomerID;
    }

    void setBudget(double newBudget){
        if(newBudget < 0)
            throw std::invalid_argument ("Not enough budget to buy a car");
        this->budget = newBudget;
    }

    // overloading operator
    bool operator<(const Customer& other) const{
        return budget < other.budget;
    }

    // methods
    void printInfoCustomer();
    void purchaseCar(Car& car);
    void addMoney(int amount);
};

int Customer::carPurchased = 0;