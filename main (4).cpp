#include "bill.hpp"
#include <iostream>


	int main() {
		string smartwatchFile = "SmartWatch.txt"; // File name for smartwatch data
		string gpsFile = "RTK_GPS.txt"; // File name for GPS data

		vector<pair<string, vector<double>>> datasets; // Vector to store datasets
		datasets.push_back(make_pair(smartwatchFile, vector<double>())); // Add smartwatch data to the vector
		datasets.push_back(make_pair(gpsFile, vector<double>())); // Add GPS data to the vector

		for (int i = 0; i < datasets.size(); i++) {
				string filename = datasets[i].first; // Get the filename
				vector<double>& lines = datasets[i].second; // Get the lines vector

				ifstream file(filename); //
				if (!file.is_open()) {
						cout << "Error opening file: " << filename << endl;
						return 1;
				}

				double value;
				while (file >> value) {
						lines.push_back(value);
				}
				file.close();
		}

		Bill bill; // Create an instance of the Bill class

		for (int i = 0; i < datasets.size(); i++) {
				string filename = datasets[i].first; // Get the filename
				vector<double> lines = datasets[i].second; // Get the lines vector

				bill.findErroneousData(lines, filename); // Detect erroneous data in the dataset
				bill.printSpeed(lines, filename);
		}

		double searchValue;
		cout << endl;
		cout << "Enter a value to search for: ";
		cin >> searchValue;

		for (int i = 0; i < datasets.size(); i++) {
				string filename = datasets[i].first;
				vector<double> lines = datasets[i].second;

				unordered_map<double, size_t> indexMap = bill.createSpeedIndex(lines);
				bill.searchSpeed(indexMap, searchValue, filename); // Search for a value in the dataset
		}

		return 0;
}