#include "bill.hpp"

// Constructor
Bill::Bill() {
    cout << "Let Us Begin" << endl;
}

// Destructor
Bill::~Bill() {
    cout << "The end." << endl;
}

// Detect erroneous data
void Bill::findErroneousData(const vector<double>& data, const string& sensorName) const { 
    cout << "\nDetecting erroneous data in " << sensorName << endl;
    vector<bool> valid(data.size(), true); // Initialize validity vector to true
    double lastValidValue = data[0]; // Initialize last valid value to first value in data

    for (size_t i = 1; i < data.size(); i++) {
        double change = abs(data[i] - lastValidValue); // Calculate change in value
        if (change > 10.0) { // Example threshold for valid change
            valid[i] = false;
        } else {
            lastValidValue = data[i];
        }
    }

    for (size_t i = 0; i < data.size(); i++) {
        if (!valid[i]) {
            cout << "The Data " << data[i] << " at time " << (i + 1) << " is wrong" << endl;
        }
    }
}

// Print speeds
void Bill::printSpeed(const vector<double>& lines, const string& filename) const {
    cout << "\nContents of the " << filename << " file:" << endl;
    for (size_t i = 0; i < lines.size(); i++) {
        cout << "Time: " << (i + 1) << "s, Speed: " << lines[i] << " m/s" << endl;
    }
}

// Create a map for speed indices
unordered_map<double, size_t> Bill::createSpeedIndex(const vector<double>& data) const {
    unordered_map<double, size_t> speedIndex; // Create an empty map
    for (size_t i = 0; i < data.size(); i++) {
        speedIndex[data[i]] = i; // Insert each speed and its corresponding index
    }
    return speedIndex; // Return the map
}

// Search for a value in the dataset
void Bill::searchSpeed(const unordered_map<double, size_t>& indexMap, double speed, const string& sensorName) const {
    if (indexMap.find(speed) != indexMap.end()) { // Check if the speed is in the map
        cout << "Found it! The corresponding index in " << sensorName << " is " << indexMap.at(speed) + 1 << endl;
    } else { // If the speed is not in the map
        cout << "Cannot find the data in " << sensorName << endl;
    }
}