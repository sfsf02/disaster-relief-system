#pragma once
#include <string>

using namespace std;

struct ReliefRequest {
    string locationName;
    int severity; 
    int foodNeeded;
    int medicineNeeded;
    int shelterNeeded;

    bool operator<(const ReliefRequest& other) const {
        return severity < other.severity; 
    }
};