#include <iostream>
#include "InventoryManager.h"
#include<ReliefRequest.h>

using namespace std;

class InventoryManager {
private:
    // [0] Food, [1] Medicine, [2] Shelter
    int availableSupplies[3];

public:
    InventoryManager() {
        // Safe defaults
        availableSupplies[0] = 0;
        availableSupplies[1] = 0;
        availableSupplies[2] = 0;
    }

    // Set initial stock
    void initializeSupplies(int startingFood, int startingMedicine, int startingShelter) {
        if (startingFood < 0) startingFood = 0;
        if (startingMedicine < 0) startingMedicine = 0;
        if (startingShelter < 0) startingShelter = 0;

        availableSupplies[0] = startingFood;
        availableSupplies[1] = startingMedicine;
        availableSupplies[2] = startingShelter;
    }

    // True only if we can fully satisfy the request
    bool checkAvailability(int foodReq, int medReq, int shelterReq) {
        if (foodReq < 0 || medReq < 0 || shelterReq < 0) return false;

        return (availableSupplies[0] >= foodReq &&
                availableSupplies[1] >= medReq &&
                availableSupplies[2] >= shelterReq);
    }

    // Deduct supplies (call this only after checkAvailability == true)
    void deductSupplies(int foodReq, int medReq, int shelterReq) {
        if (!checkAvailability(foodReq, medReq, shelterReq)) return;

        availableSupplies[0] -= foodReq;
        availableSupplies[1] -= medReq;
        availableSupplies[2] -= shelterReq;
    }

    // Optional: getters (useful for Person C)
    int getFoodStock() const { return availableSupplies[0]; }
    int getMedicineStock() const { return availableSupplies[1]; }
    int getShelterStock() const { return availableSupplies[2]; }

    // Print current stock levels
    void printInventoryReport() const {
        cout << "\n--- Current Inventory Levels ---\n";
        cout << "Food:     " << availableSupplies[0] << "\n";
        cout << "Medicine: " << availableSupplies[1] << "\n";
        cout << "Shelter:  " << availableSupplies[2] << "\n";
    }
};