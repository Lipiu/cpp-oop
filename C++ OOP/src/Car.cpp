#include <iostream>
#include "../headers/Car.h"

// method for printing info about the cars
void Car::printInfoCar(){
        std::cout << std::endl;
        std::cout << "Manufacturer: " << this->manufacturer << std::endl;
        std::cout << "Model: " << this->model << std::endl;
        std::cout << "Transmission: "<< this->transmissionType << std::endl;
        std::cout << "Production year: "<< this->yearOfProduction << std::endl;
        std::cout << "Features: " << this->features << std::endl;
        std::cout << "Horse power (hp): "<< this->horsePower << std::endl;
        std::cout << "Torque (NM): "<< this->torque << std::endl;
        std::cout << "Safety rating (1 [lowest] - 5 [highest]): "<< this->safetyRating << std::endl;
        std::cout << "Price ($): "<< this->price << std::endl;
        std::cout << "Top speed (Km/h): "<< this->topSpeed << std::endl;
}

// method for checking how many cars exist
void Car::checkCarsInStock(){
    std::cout << this->manufacturer << " " << this->model << " available in stock: " << carsInStock << std::endl;
}

void customDelay(int seconds) {
    long long int count = 0;
    long long int delayTime = 10000;
    
    for (int i = 0; i < seconds; ++i) {
        for (long long int j = 0; j < delayTime; ++j) {
            count++;
        }
    }
}

// start engine method
void Car::startEngine() {
    if(this->fuelTank > 0){
        std::cout << "Engine starting. Please wait!" << std::endl;
        customDelay(5);
        isEngineRunning = true;
    }
    else{
        std::cout << "Cannot start car. No fuel in the tank!" << std::endl;
        return;
    }

    int previousLevel = -1;

    while(this->fuelTank > 0) {
        if(!isEngineRunning){
            std::cout << "Engine stopped by function." << std::endl;
            return ;
        }
        int currentFuelLevel = this->fuelTank;
        int percentage = (currentFuelLevel * 100) / 100;
        
        if(currentFuelLevel % 25 == 0){
            if(previousLevel != currentFuelLevel){
                std::cout << "Fuel at: " << percentage << "%" << ", " << currentFuelLevel << " L remaining" << std::endl;
                previousLevel = currentFuelLevel;
            }
        }
        customDelay(5);
        setFuelTank(this->fuelTank - 1);
    }
    std::cout << "No fuel left in the tank, please refill!" << std::endl;
    
}

// stop engine method
void Car::stopEngine(){
    if(isEngineRunning){
        isEngineRunning = false;
        std::cout << "Engine stopped manually." << std::endl;
    }
    else{
        std::cout << "Engine is already off." << std::endl;
    }
}

// method to simulate driving
void Car::drive(float distance){
    if(!isEngineRunning){
        std::cout << "Cannot drive. Engine is stopped!" << std::endl;
        return ;
    }

    float maxDistance = fuelTank * fuelEfficiency;
    if(distance <= maxDistance){
        fuelTank -= (distance / fuelEfficiency);
        range += distance;
        std::cout << "Drove " << distance << " km. Total range: " << range << " km" << std::endl;
    }
    else{
        range += maxDistance;
        fuelTank = 0;
        isEngineRunning = false;
        std::cout << "Out of fuel. Car stopped after " << range << " km" << std::endl;
    }
}

// method to refuel
void Car::refuel(){
    if(fuelTank >= maxFuelTankCapacity){
        std::cout << "Tank is already full!" << std::endl;
        return ;
    }

    std::string input;
    std::cout << "Current fuel level: " << fuelTank << std::endl;
    std::cout << "Do you want to refuel?: ";
    std::cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + ('a' - 'A');
        }
    }

    if(input == "yes"){
        float refuelAmount = 0;
        std::cout << "How many liters?: ";
    
        // input validation
        while(!(std::cin >> refuelAmount) || refuelAmount <= 0){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter valid value!" << std::endl;
        }

        // prevent overfilling
        float tankAfterRefill = fuelTank + refuelAmount;
        if(tankAfterRefill > maxFuelTankCapacity)
            fuelTank = maxFuelTankCapacity;
        else{
            fuelTank += refuelAmount;
        }
        std::cout << "Car refueled. Current fuel level: " << tankAfterRefill << "L" << std::endl;
    }
}

// decrease cars in stock
void Car::decreaseStock(){
    if(carsInStock > 0)
        carsInStock--;
    else
        std::cout << "Car is out of stock!" << std::endl;

}

// method to search a car by a certain attribute
void Car::searchByAttribute(){
    std::cout << "Here you can search for a car by attributes! (type stop to exit the loop)" << std::endl;
    std::cout << "Please enter one of the following attributes:\n";
    std::cout << "Manufacturer\nModel\nYear of production(year)\nTransmission type(transmission)\nStock\n";
    std::cout << "Engine fuel(fuel)\nHorse power(hp)\nSafety rating(safety)\nTop speed(speed)\nPrice\n";

    while(true){
        std::string userInput;
        std::cin >> userInput;

        for(int i = 0; i < userInput.length(); i++)
            userInput[i] = tolower(userInput[i]);

        if (userInput == "manufacturer") {
            std::cout << "Manufacturer: " << this->manufacturer << std::endl;
        } 
        else if (userInput == "model") {
            std::cout << "Model: " << this->model << std::endl;
        } 
        else if (userInput == "year") {
            std::cout << "Year of Production: " << this->yearOfProduction << std::endl;
        }
        else if (userInput == "transmission") {
            std::cout << "Transmission Type: " << this->transmissionType << std::endl;
        }
        else if(userInput == "stock"){
            std::cout << this->manufacturer << " " << this->model << " stock: " << getCarsInStock() << std::endl;
        }
        else if (userInput == "fuel") {
            std::cout << "Type of Engine: " << this->typeOfEngine << std::endl;
        }
        else if (userInput == "hp") {
            std::cout << "Horse Power: " << this->horsePower << " HP" << std::endl;
        }
        else if (userInput == "safety") {
            std::cout << "Safety Rating: " << this->safetyRating << "/5" << std::endl;
        }
        else if (userInput == "speed") {
            std::cout << "Top Speed: " << this->topSpeed << " km/h" << std::endl;
        }
        else if (userInput == "price") {
            std::cout << "Price: $" << this->price << std::endl;
        }
        else if(userInput == "stop"){
            break;
        }
        else {
            std::cout << "Invalid attribute! Please enter a valid option." << std::endl;
        }

    }

}