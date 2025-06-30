// Corner_grocer_tracker.cpp : This purpose of this program is to help the store track items purchased at throughout the day.
// Ashley Pleasant
//6-15-25


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

// ItemTracker class takes in item frequency  from file input
class ItemTracker {
private:
    map<string, int> itemFrequency;  // Stores item names and their frequency counts

    // Converts a string to alphabetical characters only
    string cleanItemName(const string& rawItem) {
        string cleaned;
        for (char c : rawItem) {
            if (isalpha(c)) cleaned += c;
        }
        return cleaned;
    }

    // Loads items from the input file and counts their occurrences
    void loadItemsFromFile(const string& filename) {
        ifstream inFile(filename);
        string item;
        if (!inFile) {
            cerr << "Error: Could not open input file." << endl;
            exit(1);
        }

        while (inFile >> item) {
            item = cleanItemName(item);
            ++itemFrequency[item];
        }
        inFile.close();
    }

    // Saves item frequency data to a backup file named frequency.dat
    void saveFrequencyToFile(const string& filename) {
        ofstream outFile(filename);
        for (const auto& entry : itemFrequency) {
            outFile << entry.first << " " << entry.second << endl;
        }
        outFile.close();
    }

public:
    // Constructor loads data and creates backup file
    ItemTracker(const string& inputFile) {
        loadItemsFromFile(inputFile);
        saveFrequencyToFile("frequency.dat");
    }

    // Menu Option 1: Search for a specific item and show its frequency
    void printItemFrequency(const string& item) const {
        auto search = itemFrequency.find(item);
        if (search != itemFrequency.end()) {
            cout << item << " was purchased " << search->second << " times." << endl;
        }
        else {
            cout << item << " was not found in today's purchases." << endl;
        }
    }

    // Menu Option 2: Show all items with their purchase frequencies
    void printAllItems() const {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " " << entry.second << endl;
        }
    }

    // Menu Option 3: Print histogram using asterisks to represent frequency
    void printHistogram() const {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " ";
            for (int i = 0; i < entry.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// Displays the main user menu
void displayMenu() {
    cout << "\n===== Corner Grocer Menu =====" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. Display all items with frequencies" << endl;
    cout << "3. Display histogram of items" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";
}

// Main function handles menu input and user interaction
int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");
    int choice;
    string searchItem;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter item to search for: ";
            cin >> searchItem;
            tracker.printItemFrequency(searchItem);
            break;
        case 2:
            cout << "\nItem Frequencies:" << endl;
            tracker.printAllItems();
            break;
        case 3:
            cout << "\nItem Histogram:" << endl;
            tracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
