OVERALL IDEA: Car management sytem

    TODO for next time:

    - maybe replace char** with string

    - add methods:
        - start engine
        - stop engine
        - drive certain distance (lower fuel mileage/battery)
        - refuel / charge battery
        - compare cars (horsepower)
        - check if the destructor works as intended
        - search/filter cars by attributes
        - method for static variable minPrice

    - add classes:
        - Garage
            - add or remove cars from garage
        - Customers
        - Sales
            - keep track of transactions
        - Maintenance Record
            - keep track of maintenance record
        - Inventory
            - keep track of cars available or out of stock

    - inheritance:
        - Vehicle base class: Car, Truck, Electric car, etc

    - file store system

    Fixing the code - check potential memory leaks in getFeatures and setFeatures
    -----------------------------------
    What I did today:
        - added getters and setters for the new added variables
        - modified constructor and copy constructor
        - modified the TO DO list
    -----------------------------------
