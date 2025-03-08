#include <iostream>
#include <string>
#include "Car.h"


int main() {
    // Testing parameterized constructor
    const char* features1[] = {"Bluetooth", "Sunroof", "Leather seats"};
    Car car1("Toyota","Camry", 2002, const_cast<char**>(features1));

    std::cout << "Car 1 - Manufacturer: " << car1.getManufacturer() << ", Brand: " << car1.getBrand() 
              << ", Year: " << car1.getYearOfProduction() << ", Features: " << car1.getNumberOfFeatures() << std::endl;

    // Test setters
    car1.setManufacturer("Honda");
    car1.setBrand("Civic");
    car1.setYearOfProduction(2023);
    const char* features2[] = {"Navigation", "Heated seats"};
    car1.setFeatures(const_cast<char**>(features2), 2);

    std::cout << "Updated Car 1 - Manufacturer: " << car1.getManufacturer() << ", Brand: " << car1.getBrand() 
              << ", Year: " << car1.getYearOfProduction() << ", Features: " << car1.getNumberOfFeatures() << std::endl;

    // Test the copy constructor
    Car car2 = car1;  // Use copy constructor
    std::cout << "Car 2 (copy of Car 1) - Manufacturer: " << car2.getManufacturer() << ", Brand: " << car2.getBrand() 
              << ", Year: " << car2.getYearOfProduction() << ", Features: " << car2.getNumberOfFeatures() << std::endl;

    // Test 4: Test the assignment operator
    const char* features3[] = {"Backup camera", "Lane assist"};
    Car car3("Ford", "Fusion", 2021, const_cast<char**>(features3));
    car3 = car1;  // Use assignment operator
    std::cout << "Car 3 (after assignment from Car 1) - Manufacturer: " << car3.getManufacturer() << ", Brand: " << car3.getBrand() 
              << ", Year: " << car3.getYearOfProduction() << ", Features: " << car3.getNumberOfFeatures() << std::endl;

    return 0;
}
