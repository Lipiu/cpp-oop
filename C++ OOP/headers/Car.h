#include <iostream>
#include <string>
#include <cstring>


class Car{
private:
    std::string manufacturer = "";
    std::string model = "";
    std::string chassis = "";
    std::string typeOfEngine = ""; // diesel, gasoline or hybrid
    std::string transmissionType = "";
    int yearOfProduction = 0;
    float batteryPercentage = 0; // for electric cars
    float fuelTank = 100;
    float range = 0;
    std::string features = "";
    //added these today
    float fuelEfficiency = 0;
    float horsePower = 0;
    float torque = 0;
    float safetyRating = 0;
    float price = 0;
    float topSpeed = 0;
    bool isEngineRunning;

    static int carsInStock;
    static float maxFuelTankCapacity;

public:
    //default constructor
    Car(){
        carsInStock++;
    }

    //constructor with parameters
    Car(std::string manufacturer, std::string model, std::string chassis, std::string transmission, int yearOfProduction,  
        std::string features, float horsePower, float torque, float safetyRating, float price, 
        float topSpeed) {
    
        this->setManufacturer(manufacturer);
        this->setModel(model);
        this->setChassis(chassis);
        this->setTransmission(transmission);
        this->setYearOfProduction(yearOfProduction);
        this->setFeatures(features);
        this->setHorsePower(horsePower);
        this->setTorque(torque);
        this->setSafetyRating(safetyRating);
        this->setPrice(price);
        this->setTopSpeed(topSpeed);
    
        isEngineRunning = false;
        carsInStock++;
    }
    

    //copy constructor
    Car(const Car& car){
        manufacturer = car.manufacturer;
        model = car.model;
        chassis = car.chassis;
        transmissionType = car.transmissionType;
        yearOfProduction = car.yearOfProduction;
        features = car.features;
        horsePower = car.horsePower;
        torque = car.torque;
        fuelEfficiency = car.fuelEfficiency;
        safetyRating = car.safetyRating;
        price = car.price;
        topSpeed = car.topSpeed;
        fuelTank = car.fuelTank;

        carsInStock++;
    }

    //getters
    std::string getManufacturer() const{
        return this->manufacturer;
    }

    std::string getModel() const{
        return this->model;
    }

    int getYearOfProduction() const{
        return this->yearOfProduction;
    }

    std::string getTransmission() const{
        return this->transmissionType;
    }

    std::string getFeatures() const{
        return this->features;
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

    float getFuelTank() const{
        return this->fuelTank;
    }

    float getFuelEfficiency() const{
        return this->fuelEfficiency;
    }

    float getHorsePower() const{
        return this->horsePower;
    }

    float getTorque() const{
        return this->torque;
    }

    float getSafetyRating() const{
        return this->safetyRating;
    }

    float getPrice() const{
        return this->price;
    }

    float getTopSpeed() const{
        return this->topSpeed;
    }

    //setters
    void setManufacturer(std::string newManufacturer){
        if(newManufacturer.empty()){
            throw "Manufacturer field should not be empty! Exiting...";
        }

        this->manufacturer = newManufacturer;
    }

    void setModel(std::string newModel){
        if(newModel.empty()){
            throw "Model field should not be empty! Exiting...";
        }
        this->model = newModel;
    }

    void setYearOfProduction(int yearOfProduction){
        if(yearOfProduction < 1885){
            throw "First car was invented in 1885. Please enter valid year of production! Exiting...";
        }
        this->yearOfProduction = yearOfProduction;
    }

    void setTransmission(std::string transmissionType){
        if(transmissionType.empty())
            throw "Transmission field cannot be left empty! Exiting...";
        this->transmissionType = transmissionType;
    }

    void setFeatures(std::string newFeatures){
        if(newFeatures.empty())
            throw "Features field cannot be empty. Exiting...";
        this->features = newFeatures;
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

    void setFuelTank(float newFuelTank){
        if(newFuelTank < 0)
            throw "The amount of fuel in the tank cannot be negative. Exiting...";
        this->fuelTank = newFuelTank;
    }

    void setFuelEfficiency(float newFuelEfficiency){
        if(newFuelEfficiency <= 0)
            throw "Fuel efficiency cannot be negative or 0. Exiting...";
        this->fuelEfficiency = newFuelEfficiency;
    }

    void setHorsePower(float newHorsePower){
        if(newHorsePower < 0)
            throw "Horse power cannot be negative. Exiting...";
        this->horsePower = newHorsePower;
    }

    void setTorque(float newTorque){
        if(newTorque < 0){
            throw "Torque cannot be negative. Exiting...";
        }
        this->torque = newTorque;
    }

    void setSafetyRating(float newSafetyRating){
        if(newSafetyRating < 0)
            throw "Safety rating cannot be negative. Exiting...";
        this->safetyRating = newSafetyRating;
    }

    void setPrice(float newPrice){
        if(newPrice <= 0){
            throw "Price cannot be zero/negative. Please enter a valid value!";
        }
        this->price = newPrice;
    }

    void setTopSpeed(float newTopSpeed){
        if(newTopSpeed <= 0)
            throw "Top speed must cannot be zero/negative. Please enter a valid value!";
        this->topSpeed = newTopSpeed;
    }

    //operator
    

    // methods declaration
    void printInfo();
    void checkCarsInStock();
    void startEngine();
    void stopEngine();
    void drive(float distance);
    void refuel();
};

int Car::carsInStock = 0;
float Car::maxFuelTankCapacity = 100; // all cars come with a fuel tank from factory
