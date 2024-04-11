#include <iostream>
#include <string>
#include "File.h"
#include "FileVersion.h"
#include "VersionControlManager.h"

void printMenu() {
    std::cout << "Меню:\n";
    std::cout << "1. Добавить файл\n";
    std::cout << "2. Добавить версию файла\n";
    std::cout << "3. Вывести все версии файла\n";
    std::cout << "4. Вывести конфигурации по дате\n";
    std::cout << "5. Вывести конфигурацию по номеру версии\n";
    std::cout << "6. Вывести конфигурации по состоянию\n";
    std::cout << "0. Выйти\n";
}

int main() {
    VersionControlManager manager;

    int choice;
    do {
        printMenu();
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string filename;
            std::cout << "Введите название файла: ";
            std::cin >> filename;
            manager.addFile(filename);
            std::cout << "Файл добавлен.\n";
            break;
        }
        case 2: {
            std::string filename, date;
            int number;
            bool isFixed;

            std::cout << "Введите название файла: ";
            std::cin >> filename;
            std::cout << "Введите номер версии: ";
            std::cin >> number;
            std::cout << "Введите дату версии (ГГГГ-ММ-ДД): ";
            std::cin >> date;
            std::cout << "Фиксированная версия? (1 для да, 0 для нет): ";
            std::cin >> isFixed;

            manager.addVersion(filename, FileVersion(number, date, isFixed));
            std::cout << "Версия добавлена.\n";
            break;
        }
        case 3: {
            std::string filename;
            std::cout << "Введите название файла: ";
            std::cin >> filename;
            manager.printAllFileVersions(filename);
            break;
        }
        case 4: {
            std::string date;
            std::cout << "Введите дату (ГГГГ-ММ-ДД): ";
            std::cin >> date;
            manager.printConfigurationsByDate(date);
            break;
        }
        case 5: {
            int versionNumber;
            std::cout << "Введите номер версии: ";
            std::cin >> versionNumber;
            manager.printConfigurationByVersion(versionNumber);
            break;
        }
        case 6: {
            bool isFixed;
            std::cout << "Введите состояние (1 для фиксированной, 0 для редактируемой): ";
            std::cin >> isFixed;
            manager.printConfigurationsByState(isFixed);
            break;
        }
        case 0:
            std::cout << "Выход из программы...\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

