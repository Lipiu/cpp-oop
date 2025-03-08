#include <iostream>
#include <string>
#include <cstring>


class Car{
private:
    std::string manufacturer = "";
    std::string brand = "";
    std::string chassis = "";
    std::string typeOfEngine = ""; // diesel, gasoline or hybrid
    std::string transmissionType = "";
    int yearOfProduction = 0;
    int numberOfFeatures = 0;
    float batteryPercentage = 0; // for electric cars
    float range = 0;
    char** features = nullptr;
    //added these today
    float fuelEfficiency = 0;
    float horsePower = 0;
    float torque = 0;
    float safetyRating = 0;
    float price = 0;
    float topSpeed = 0;

public:
    //default constructor
    Car(){}

    //constructor with parameters
    Car(std::string manufacturer, std::string brand, int yearOfProduction, char** features){
        this->setManufacturer(manufacturer);
        this->setBrand(brand);
        this->setYearOfProduction(yearOfProduction);
        this->setFeatures(features, numberOfFeatures);
    }

    //copy constructor
    Car(const Car& car){
        manufacturer = car.manufacturer;
        brand = car.brand;
        yearOfProduction = car.yearOfProduction;

        //Creating deep copy in order to avoid shallow copy 
        if(car.features != nullptr){
            numberOfFeatures = car.numberOfFeatures;
        
            this->features = new char*[numberOfFeatures];

            for(int i = 0; i < numberOfFeatures; i++){
                this->features[i] = new char[strlen(car.features[i]) + 1];
                strcpy(this->features[i], car.features[i]);
            }
        }
        else{
            this->features = nullptr;
        }

    }

    //destructor
    ~Car(){
        for(int i = 0; i < numberOfFeatures; i++){
            delete[] this->features[i];
        }
        delete[] this->features;
        this->features = nullptr;
    }

    //getters
    std::string getManufacturer() const{
        return this->manufacturer;
    }

    std::string getBrand() const{
        return this->brand;
    }

    int getYearOfProduction() const{
        return this->yearOfProduction;
    }

    char** getFeatures() const{
        char** copy = new char*[this->numberOfFeatures];

        for(int i = 0; i < this->numberOfFeatures; i++){
            copy[i] = new char[strlen(this->features[i]) + 1];
            strcpy(copy[i], this->features[i]);
        }

        return copy;
    }

    int getNumberOfFeatures() const{
        return this->numberOfFeatures;
    }

    std::string getChassis() const{
        return this->chassis;
    }

    std::string getTypeOfEngine() const{
        return this->typeOfEngine;
    }

    float getRange() const{
        return this->range;
    }

    float getBatteryPercentage() const{
        return this->batteryPercentage;
    }

    //setters
    void setManufacturer(std::string newManufacturer){
        if(newManufacturer.empty()){
            throw "Manufacturer field should not be empty! Exiting...";
        }

        this->manufacturer = newManufacturer;
    }

    void setBrand(std::string newBrand){
        if(newBrand.empty()){
            throw "Brand field should not be empty! Exiting...";
        }
        this->brand = newBrand;
    }

    void setYearOfProduction(int yearOfProduction){
        if(yearOfProduction < 1885){
            throw "First car was invented in 1885. Please enter valid year of production! Exiting...";
        }
        this->yearOfProduction = yearOfProduction;
    }

    void setFeatures(char** newFeatures, int newNumberOfFeatures){
        if(newFeatures != nullptr){
            char** copy = new char*[newNumberOfFeatures];

            for(int i = 0; i < newNumberOfFeatures; i++){
                copy[i] = new char[strlen(newFeatures[i]) + 1];
                strcpy(copy[i], newFeatures[i]);
            }
            if(features != nullptr){
                for(int i = 0; i < numberOfFeatures; i++)
                    delete[] this->features[i];
                delete[] this->features;
            }

            this->features = copy;
            this->numberOfFeatures = newNumberOfFeatures;
        }
        else{
            throw "Features field cannot be left empty. Exiting...";
        }
    }

    void setChassis(std::string newChassis){
        if(newChassis.empty())
            throw "Chassis field cannot be left empty. Exiting...";
        this->chassis = newChassis;
    }

    void setTypeOfEngine(std::string newTypeOfEngine){
        if(newTypeOfEngine.empty())
            throw "Type of engine field cannot be left empty. Exiting...";
        this->typeOfEngine = newTypeOfEngine;
    }

    void setRange(int newRange){
        if(newRange < 0)
            throw "Range cannot be negative. Exiting...";
        this->range = newRange;
    }

    void setBatteryPercentage(int newBatteryPercentage){
        if(newBatteryPercentage < 0)
            throw "Battery percentage cannot be negative. Exiting...";
        this->batteryPercentage = newBatteryPercentage;
    }

    //operator
    Car& operator=(const Car& car){
        //to prevent car1 = car1
        if(this == &car){
            return *this;
        }

        if(this->features != nullptr){
            for(int i = 0; i < numberOfFeatures; i++)
                delete[] this->features[i];
            delete[] this->features;
            this->features = nullptr;
        }

        this->numberOfFeatures = car.numberOfFeatures;
        this->features = new char*[numberOfFeatures];
        for(int i = 0; i < numberOfFeatures; i++){
            this->features[i] = new char[strlen(car.features[i]) + 1];
            strcpy(this->features[i], car.features[i]);
        }
        return *this;
    }
};