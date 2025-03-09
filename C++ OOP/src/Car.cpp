#include <iostream>
#include "../headers/Car.h"

void Car::printInfo(){
        std::cout << std::endl;
        std::cout << "Manufacturer: " << this->manufacturer << std::endl;
        std::cout << "Brand: " << this->brand;
        std::cout << "Chassis: "<< this->chassis << std::endl;
        std::cout << "Type of engine: "<< this->typeOfEngine << std::endl;
        std::cout << "Transmission: "<< this->transmissionType << std::endl;
        std::cout << "Production year: "<< this->yearOfProduction << std::endl;
        std::cout << "Number of features: "<< this->numberOfFeatures << std::endl;
        std::cout << "Range: "<< this->range << std::endl;

        if(this->features != nullptr){
            std::cout << "Features: ";
            for(int i = 0; i < this->numberOfFeatures; i++){
                std:: cout << this->features[i];
                if(i < this->numberOfFeatures - 1)
                    std::cout << ",";
            }
            std::cout << std::endl;
        }

        std::cout << "Fuel efficiency (L/KM): "<< this->fuelEfficiency << std::endl;
        std::cout << "Horse power (hp): "<< this->horsePower << std::endl;
        std::cout << "Torque (NM): "<< this->torque << std::endl;
        std::cout << "Safety rating (1 [lowest] - 5 [highest]): "<< this->safetyRating << std::endl;
        std::cout << "Price ($): "<< this->price << std::endl;
        std::cout << "Top speed (Km/h): "<< this->topSpeed << std::endl;
}