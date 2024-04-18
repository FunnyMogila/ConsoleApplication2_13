#include <iostream>
#include <string>
#include "File.h"
#include "FileVersion.h"
#include "VersionControlManager.h"

void printMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add a file\n";
    std::cout << "2. Add a file version\n";
    std::cout << "3. Print all versions of a file\n";
    std::cout << "4. Print configurations by date\n";
    std::cout << "5. Print configuration by version number\n";
    std::cout << "6. Print configurations by state\n";
    std::cout << "0. Exit\n";
}

int main() {
    VersionControlManager manager;

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string filename;
            std::cout << "Enter the filename: ";
            std::cin >> filename;
            manager.addFile(filename);
            std::cout << "File added.\n";
            break;
        }
        case 2: {
            std::string filename, date;
            int number;
            bool isFixed;

            std::cout << "Enter the filename: ";
            std::cin >> filename;
            std::cout << "Enter the version number: ";
            std::cin >> number;
            std::cout << "Enter the version date (YYYY-MM-DD): ";
            std::cin >> date;
            std::cout << "Is it a fixed version? (1 for yes, 0 for no): ";
            std::cin >> isFixed;

            manager.addVersion(filename, FileVersion(number, date, isFixed));
            std::cout << "Version added.\n";
            break;
        }
        case 3: {
            std::string filename;
            std::cout << "Enter the filename: ";
            std::cin >> filename;
            manager.printAllFileVersions(filename);
            break;
        }
        case 4: {
            std::string date;
            std::cout << "Enter the date (YYYY-MM-DD): ";
            std::cin >> date;
            manager.printConfigurationsByDate(date);
            break;
        }
        case 5: {
            int versionNumber;
            std::cout << "Enter the version number: ";
            std::cin >> versionNumber;
            manager.printConfigurationByVersion(versionNumber);
            break;
        }
        case 6: {
            bool isFixed;
            std::cout << "Enter the state (1 for fixed, 0 for editing): ";
            std::cin >> isFixed;
            manager.printConfigurationsByState(isFixed);
            break;
        }
        case 0:
            std::cout << "Exiting the program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}


