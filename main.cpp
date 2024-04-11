#include <iostream>
#include <string>
#include "File.h"
#include "FileVersion.h"
#include "VersionControlManager.h"

void printMenu() {
    std::cout << "����:\n";
    std::cout << "1. �������� ����\n";
    std::cout << "2. �������� ������ �����\n";
    std::cout << "3. ������� ��� ������ �����\n";
    std::cout << "4. ������� ������������ �� ����\n";
    std::cout << "5. ������� ������������ �� ������ ������\n";
    std::cout << "6. ������� ������������ �� ���������\n";
    std::cout << "0. �����\n";
}

int main() {
    VersionControlManager manager;

    int choice;
    do {
        printMenu();
        std::cout << "������� ��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string filename;
            std::cout << "������� �������� �����: ";
            std::cin >> filename;
            manager.addFile(filename);
            std::cout << "���� ��������.\n";
            break;
        }
        case 2: {
            std::string filename, date;
            int number;
            bool isFixed;

            std::cout << "������� �������� �����: ";
            std::cin >> filename;
            std::cout << "������� ����� ������: ";
            std::cin >> number;
            std::cout << "������� ���� ������ (����-��-��): ";
            std::cin >> date;
            std::cout << "������������� ������? (1 ��� ��, 0 ��� ���): ";
            std::cin >> isFixed;

            manager.addVersion(filename, FileVersion(number, date, isFixed));
            std::cout << "������ ���������.\n";
            break;
        }
        case 3: {
            std::string filename;
            std::cout << "������� �������� �����: ";
            std::cin >> filename;
            manager.printAllFileVersions(filename);
            break;
        }
        case 4: {
            std::string date;
            std::cout << "������� ���� (����-��-��): ";
            std::cin >> date;
            manager.printConfigurationsByDate(date);
            break;
        }
        case 5: {
            int versionNumber;
            std::cout << "������� ����� ������: ";
            std::cin >> versionNumber;
            manager.printConfigurationByVersion(versionNumber);
            break;
        }
        case 6: {
            bool isFixed;
            std::cout << "������� ��������� (1 ��� �������������, 0 ��� �������������): ";
            std::cin >> isFixed;
            manager.printConfigurationsByState(isFixed);
            break;
        }
        case 0:
            std::cout << "����� �� ���������...\n";
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

