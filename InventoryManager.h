#pragma once
#include <iostream>

class InventoryManager {
private:
    // [0] Food, [1] Medicine, [2] Shelter
    int availableSupplies[3];

public:
    // Constructor
    InventoryManager();

    // Initialize stock levels
    void initializeSupplies(int startingFood, int startingMedicine, int startingShelter);

    // Check if full request can be satisfied
    bool checkAvailability(int foodReq, int medReq, int shelterReq);

    // Deduct supplies (only call if checkAvailability is true)
    void deductSupplies(int foodReq, int medReq, int shelterReq);

    // Getters
    int getFoodStock() const;
    int getMedicineStock() const;
    int getShelterStock() const;

    // Print inventory report
    void printInventoryReport() const;
};