#include <iostream>
#include "ReliefRequest.h"
#include <string>
#include <sstream> // to segemnt text based on Delimiters
#include <fstream>
#include "InventoryManager.h"
#include "RequestQueue.h"
#include <vector>
using namespace std;
void generateReport(string outputFileName,vector<ReliefRequest>& Success,vector<ReliefRequest>& Fail, InventoryManager& Inventory) {
    // Create and open a new text file
    ofstream reportFile(outputFileName);

    if (reportFile.is_open()) {
        reportFile << "==========================================\n";
        reportFile << "   DISASTER RELIEF DISTRIBUTION REPORT    \n";
        reportFile << "==========================================\n\n";
        
        // Print the Successful Deliveries
        reportFile << "✅ SUCCESSFULLY FULFILLED REQUESTS:\n";
        reportFile << "------------------------------------------\n";
        for (size_t i = 0; i < Success.size(); i++) {
            reportFile << "- " << Success[i].locationName 
                       << " (Severity " << Success[i].severity << ")\n";
        }
        reportFile << "\n";

        // Print the Failed Deliveries
        reportFile << "❌ UNFULFILLED REQUESTS (Not enough supplies):\n";
        reportFile << "------------------------------------------\n";
        for (size_t i = 0; i < Fail.size(); i++) {
            reportFile << "- " << Fail[i].locationName 
                       << " (Severity " << Fail[i].severity << ")\n";
        }
        reportFile << "\n";

        // Print Remaining Inventory
        reportFile << "📦 REMAINING INVENTORY LEVELS:\n";
        reportFile << "------------------------------------------\n";
        reportFile << "- Food: " << Inventory.getFoodStock() << " units\n";
        reportFile << "- Medicine: " << Inventory.getMedicineStock() << " units\n";
        reportFile << "- Shelter: " << Inventory.getShelterStock() << " units\n";

        reportFile.close();
        cout << "Success: Report saved to " << outputFileName << endl;
    } else {
        cout << "Error: Could not create the report file." << endl;
    }
}

int main(int argc , char* argv[]) {
    if (argc < 2) {
        cout << "Usage Error. Please run the program like this: " << endl;
        cout << "./relief_system <input_file.txt>" << endl;
        return 1; // Exit 
    }

    cout << "Disaster Relief System Initialized." << endl;
    vector<ReliefRequest> successRequest,failedRequest;
    InventoryManager inventory;
    RequestQueue queue;
    int foodSupply,medicineSupply,shelterSupply;
    cout<<"how many supplies you have for food,medicine,shelter?"<<endl;
    cin>>foodSupply>>medicineSupply>>shelterSupply;
    inventory.initializeSupplies(foodSupply,medicineSupply,shelterSupply);

    string fileInput= argv[1];
    cout<<"Loading disaster requests from: " << fileInput << "...\n" << endl;
    ifstream inFile(fileInput);
    if(!(inFile.is_open())){
        cout << "Error: Could not find or open the file " << fileInput << endl;
        return 1;
    }
    string line; // to get each line of the file 
    while (getline(inFile,line))
     {
        stringstream ss(line);
        string location,temstr;
        int severity, foodNeeded , medicineNeeded , shelterNeeded;
        // get the location name 
        getline(ss, location , ',');
        // get the sverity of the location 
        getline(ss , temstr, ',');
        severity = stoi(temstr);
        // get the amount of food needed  
        getline(ss , temstr, ',');
        foodNeeded = stoi(temstr);
        // get the amount of medicine needed  
        getline(ss , temstr, ',');
        medicineNeeded = stoi(temstr);
        // get the samount of shelter needed
        getline(ss , temstr, ',');
        shelterNeeded = stoi(temstr);
        ReliefRequest newRequest ={location,severity,foodNeeded,medicineNeeded,shelterNeeded};
        queue.addRequest(newRequest);
     }
    inFile.close();
    while (!(queue.isEmpty()))
    {   
    
        ReliefRequest Request;
        Request = queue.getNextRequest();
        if(inventory.checkAvailability(Request.foodNeeded,Request.medicineNeeded,Request.shelterNeeded)){
            inventory.deductSupplies(Request.foodNeeded,Request.medicineNeeded,Request.shelterNeeded);
            successRequest.push_back(Request);
        }else{
            failedRequest.push_back(Request);
        }
    }
    generateReport("Distrubution_Reprot",successRequest,failedRequest,inventory);
    cout << "\nThank you for Using this program!" << endl;

    return 0;
}

