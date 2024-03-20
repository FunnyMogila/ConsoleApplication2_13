#include <iostream>
#include "File.h"
#include "FileVersion.h"
#include "VersionControlManager.h"

int main() {
    // Создание менеджера контроля версий приложения
    VersionControlManager manager;

    // Добавление файлов
    manager.addFile("file1.txt");
    manager.addFile("file2.txt");

    // Добавление версий файлов
    manager.addVersion("file1.txt", FileVersion(1, "2024-03-20", true));
    manager.addVersion("file1.txt", FileVersion(2, "2024-03-21", false));
    manager.addVersion("file2.txt", FileVersion(1, "2024-03-20", true));
    manager.addVersion("file2.txt", FileVersion(2, "2024-03-21", true));

    // Получение информации о версиях файлов
    manager.printAllFileVersions("file1.txt");
    manager.printAllFileVersions("file2.txt");

    // Построение конфигураций приложения по дате версий, номеру версий и состоянию версий
    manager.printConfigurationsByDate("2024-03-20");
    manager.printConfigurationByVersion(2);
    manager.printConfigurationsByState(true);

    return 0;
}
