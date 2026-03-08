#include <iostream>
#include "InventoryManager.h"

using namespace std;




InventoryManager::InventoryManager() {
        // Safe defaults
        availableSupplies[0] = 0;
        availableSupplies[1] = 0;
        availableSupplies[2] = 0;
    }

    // Set initial stock
  void  InventoryManager:: initializeSupplies(int startingFood, int startingMedicine, int startingShelter) {
        if (startingFood < 0) startingFood = 0;
        if (startingMedicine < 0) startingMedicine = 0;
        if (startingShelter < 0) startingShelter = 0;

        availableSupplies[0] = startingFood;
        availableSupplies[1] = startingMedicine;
        availableSupplies[2] = startingShelter;
    }

    // True only if we can fully satisfy the request
    bool  InventoryManager::checkAvailability(int foodReq, int medReq, int shelterReq) {
        if (foodReq < 0 || medReq < 0 || shelterReq < 0) return false;

        return (availableSupplies[0] >= foodReq &&
                availableSupplies[1] >= medReq &&
                availableSupplies[2] >= shelterReq);
    }

    // Deduct supplies (call this only after checkAvailability == true)
    void InventoryManager::deductSupplies(int foodReq, int medReq, int shelterReq) {
        if (!checkAvailability(foodReq, medReq, shelterReq)) return;

        availableSupplies[0] -= foodReq;
        availableSupplies[1] -= medReq;
        availableSupplies[2] -= shelterReq;
    }

    // Optional: getters (useful for Person C)
    int InventoryManager::getFoodStock() const { return availableSupplies[0]; }
    int InventoryManager::getMedicineStock() const { return availableSupplies[1]; }
    int InventoryManager::getShelterStock() const { return availableSupplies[2]; }

    // Print current stock levels
    void InventoryManager::printInventoryReport() const {
        cout << "\n--- Current Inventory Levels ---\n";
        cout << "Food:     " << availableSupplies[0] << "\n";
        cout << "Medicine: " << availableSupplies[1] << "\n";
        cout << "Shelter:  " << availableSupplies[2] << "\n";
    }
