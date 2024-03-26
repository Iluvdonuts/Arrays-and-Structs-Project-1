// This program analyzes marathon runners weekly data
// The program reads input data from a file containing the runners names and the number of miles they run each day
// With the data provides calculates the total miles run by each runner for the week and their average daily mileage
// Finally it presents thge results in a formatted table displaying each runners name dailey mileage and average daily mileage

#include <iostream>
#include <fstream>
#include <iomanip>

const int NUM_RUNNERS = 5;
const int DAYS_IN_WEEK = 7;

void readDataFromFile(std::string runners[], int milesRun[][DAYS_IN_WEEK]);
void calculateTotalsAndAverages(const std::string runners[], const int milesRun[][DAYS_IN_WEEK]);
void outputResults(const std::string runners[], const int milesRun[][DAYS_IN_WEEK]);

int main() {
	std::string runners[NUM_RUNNERS];
	int milesRun[NUM_RUNNERS][DAYS_IN_WEEK];

	readDataFromFile(runners, milesRun);
	calculateTotalsAndAverages(runners, milesRun);
	outputResults(runners, milesRun);

	return 0;
}

void readDataFromFile(std::string runners[], int milesRun[][DAYS_IN_WEEK]) {
	std::ifstream inputFile("input_data.txt");
	if (!inputFile) {
		std::cerr << "Error: Unable to open Input file. \n";
		exit(1);
	}

	for (int i = 0; i < NUM_RUNNERS; ++i) {
		inputFile >> runners[i];
		std::cout << "Runner: " << runners[i] << std::endl;
		for (int j = 0; j < DAYS_IN_WEEK; ++j) {
			inputFile >> milesRun[i][j];
			std::cout << "Miles run on day " << j + 1 << ": " << milesRun[i][j] << std::endl;
	    }
	}

	inputFile.close();
}

void calculateTotalsAndAverages(const std::string runners[], const int milesRun[][DAYS_IN_WEEK]) {
	for (int i = 0; i < NUM_RUNNERS; ++i) {
		int totalMiles = 0;
		for (int j = 0; j < DAYS_IN_WEEK; ++j) {
			totalMiles += milesRun[i][j];
		}
		double averageMiles = static_cast<double>(totalMiles) / DAYS_IN_WEEK;
		std::cout << "Totals miles for " << runners[i] << ": " << totalMiles << "\n";
		std::cout << "Average miles per day for " << runners[i] << ": " << averageMiles << "\n";
    }
}

void outputResults(const std::string runners[], const int milesRun[][DAYS_IN_WEEK]) {
	std::cout << std::setw(15) << std::left << "Runner";
	for (int day = 0; day < DAYS_IN_WEEK; ++day) {
		std::cout << std::setw(8) << std::right << "Day " << day + 1;
	}
	std::cout << std::setw(12) << std::right << "Total";
	std::cout << std::setw(12) << std::right << "Average\n";

	for (int i = 0; i < NUM_RUNNERS; ++i) {
		std::cout << std::setw(15) << std::left << runners[i];
		int totalMiles = 0;
		for (int j = 0; j < DAYS_IN_WEEK; ++j) {
			std::cout << std::setw(8) << std::right << milesRun[i][j];
			totalMiles += milesRun[i][j];
		}
		double averageMiles = static_cast<double>(totalMiles) / DAYS_IN_WEEK;
		std::cout << std::setw(12) << std::right << totalMiles;
		std::cout << std::setw(12) << std::right << std::fixed << std::setprecision(2) << averageMiles << "\n";
	}
}


