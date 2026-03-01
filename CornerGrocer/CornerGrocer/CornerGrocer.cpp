/* 
Krisztofer Lindh - CS210 - Project 3 - Corner Grocer
This program reads a list of grocery items from a file, 
counts the frequency of each item, 
and provides a menu for the user to interact with the data. 
The user can get the frequency of a specific item, 
print all item frequencies, 
or display a histogram of item frequencies. 
The program also writes the frequency data to a backup file.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm> 
#include <cctype> 
using namespace std;

// GroceryTracker class definition
class GroceryTracker {
// Private members to store item frequencies and item names
private:
	map<string, int> itemFrequency;
	string itemName;
// Public member functions to load file, get frequency, print histogram, print frequencies, and write backup file
public:
	void loadFile(string filename);
	int getFrequency(string item);
	void printHistogram();
	void printFrequencies();
	void writeBackupFile(string filename);
	string toLowerCase(string data) {
		transform(data.begin(), data.end(), data.begin(),
			[](unsigned char c) { return tolower(c); });
		return data;
	}

};
// Implementation of GroceryTracker member functions
void GroceryTracker::loadFile(string filename) {
	ifstream inputFile(filename);
	string tempItem;
	// Check if the file was opened successfully
	while (inputFile >> tempItem) {
		// Convert item name to lowercase and update frequency in the map
		itemFrequency[toLowerCase(tempItem)]++;
	}
	inputFile.close();
}
// Function to get the frequency of a specific item
int GroceryTracker::getFrequency(string item) {
	string searchKey = toLowerCase(item); // Normalize the user input
	auto it = itemFrequency.find(searchKey);
	if (it != itemFrequency.end()) {
		return it->second;
	}
	return 0;
}
// Function to print a histogram of item frequencies
void GroceryTracker::printHistogram() {
	for (const auto& pair : itemFrequency) {
		string displayLabel = pair.first;
		if (!displayLabel.empty()) {
			displayLabel[0] = toupper(displayLabel[0]); // Capitalize first letter for display
		}
		cout << setw(12) << right << displayLabel << " " << string(pair.second, '*') << endl;
	}
}
// Function to print the frequencies of all items
void GroceryTracker::printFrequencies() {
	for (const auto& pair : itemFrequency) {
		string displayLabel = pair.first;
		if (!displayLabel.empty()) {
			displayLabel[0] = toupper(displayLabel[0]); // Capitalize for consistency
		}
		cout << displayLabel << ": " << pair.second << endl;
	}
}
// Function to write the item frequencies to a backup file
void GroceryTracker::writeBackupFile(string filename) {
	ofstream outputFile(filename);
	if (!outputFile.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return;
	}
	for (const auto& pair : itemFrequency) {
		outputFile << pair.first << ": " << pair.second << endl;
	}
	outputFile.close();
}


int main()
{
	// Variable to store the item name for frequency search
	string searchItem;
	// Create an instance of GroceryTracker and load the input file, then write the backup file
	GroceryTracker tracker;
	tracker.loadFile("CS210_Project_Three_Input_File.txt");
	tracker.writeBackupFile("frequency.dat");
	// Main menu loop to interact with the user
	while (true) {
		cout << "===== Corner Grocer Main Menu =====" << endl;
		cout << "      1. Get Frequency of Item     " << endl;
		cout << "      2. Print Frequencies         " << endl;
		cout << "      3. Print Histogram           " << endl;
		cout << "      4. Exit                      " << endl;
		cout << string(35, '=') << endl;
		int choice;
		cout << "Please Select A Menu Item: ";
		cin >> choice;
		// Validate user input for menu choice
		if (cin.fail()) {
			cin.clear(); // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << string(35, '=') << endl;
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			cout << string(35, '=') << endl;

			continue; // Restart the loop
		}
		// Handle user choices using a switch statement
		switch (choice) {
		// Prompt user for item name and display its frequency
		case 1:
			cout << string(35, '=') << endl;
			cout << "Enter item name: ";
			cin >> searchItem;
			cout << "Frequency of " << searchItem << ": " << tracker.getFrequency(searchItem) << endl;
			cout << string(35, '=') << endl;
			break;
		// Print frequencies of all items using the printFrequencies function
		case 2:
			cout << string(35, '=') << endl;
			tracker.printFrequencies();
			cout << string(35, '=') << endl;
			break;
		// Print a histogram of item frequencies using the printHistogram function
		case 3:
			cout << string(35, '=') << endl;
			tracker.printHistogram();
			cout << string(35, '=') << endl;
			break;
		// Exit the program
		case 4:
			cout << string(35, '=') << endl;
			return 0;
		default:
			cout << string(35, '=') << endl;
			cout << "Invalid choice. Please try again." << endl;
			cout << string(35, '=') << endl;
		}
	}

}