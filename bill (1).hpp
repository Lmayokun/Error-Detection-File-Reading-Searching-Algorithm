#ifndef BILL_HPP
#define BILL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map> // Include the unordered_map header for hashtable
#include <cmath>

using namespace std;

class Bill { // Class Bill
public:
    // Constructor
    Bill();

    // Destructor
    ~Bill();

    // Detect erroneous data in the dataset
    void findErroneousData(const vector<double>& data, const string& sensorName) const;

    // Print speeds from the dataset
    void printSpeed(const vector<double>& lines, const string& filename) const;

    // Search for a value in the dataset
    void searchSpeed(const unordered_map<double, size_t>& indexMap, double speed, const string& sensorName) const;

    // Create a map for speed indices
    unordered_map<double, size_t> createSpeedIndex(const vector<double>& data) const;
};

#endif // BILL_HPP