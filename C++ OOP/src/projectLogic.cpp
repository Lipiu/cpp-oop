#pragma once
#include "../headers/Car.h"
#include "../headers/Customer.h"
#include "../headers/Garage.h"
#include <iostream>
#include <vector>

void projectLogic() {
    std::cout << "Welcome to my car management system!" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    // Sample cars
    Car car1("Toyota", "Supra", "Automatic", 2023, "Sport package", 300, 320, 3, 20000, 200);
    Car car2("Tesla", "Model S", "Automatic", 2024, "Autopilot, Full Self-Driving", 300, 320, 3, 20000, 200);

    // Garage with available cars
    Garage g;
    g.addCar(car1);
    g.addCar(car2);

    // Customer with budget
    Customer cust("John", "Doe", 30, "john.doe@example.com", "0734953458");

    int input;
    int isRunning = true;
    while(isRunning){
        std::cout << "\n1. Buy car\n2. See cars in stock\n3. See my garage\n4. Add money\n5. Exit\n";
        std::cout << "Enter the digit to select an option: ";
        std::cin >> input;

        switch (input) {
            // buy car
            case 1: {
                if (g.getTotalCars() == 0) {
                    std::cout << "No cars available for purchase.\n";
                    break;
                }

                std::cout << "Available cars:\n";
                car1.printInfoCar();
                car2.printInfoCar();

                int carIndex;
                std::cout << "Enter 1 for Toyota Supra or 2 for Tesla Model S: ";
                std::cin >> carIndex;

                Car* selectedCar = nullptr;
                if (carIndex == 1) {
                    selectedCar = &car1;
                } else if (carIndex == 2) {
                    selectedCar = &car2;
                }

                if (selectedCar) {
                    cust.purchaseCar(*selectedCar);
                    g.removeCar(*selectedCar);
                } else {
                    std::cout << "Invalid selection.\n";
                }
                break;
            }

            // Show cars in stock
            case 2:
                g.getTotalCars();
                break;

            // Show customer's garage
            case 3:
                std::cout << "Cars in your garage: " << g.getTotalCars() << std::endl;
                break;

            // Add money
            case 4: {
                std::cout << "Current budget: $" << cust.getBudget() << std::endl;
                float amountToAdd;
                std::cout << "Enter amount to add: ";
                std::cin >> amountToAdd;
                cust.addMoney(amountToAdd);
                break;
            }

            // Exit
            case 5:
                isRunning = false;
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }
}
