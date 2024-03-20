#include <iostream>
#include "File.h"
#include "FileVersion.h"
#include "VersionControlManager.h"

int main() {
    // �������� ��������� �������� ������ ����������
    VersionControlManager manager;

    // ���������� ������
    manager.addFile("file1.txt");
    manager.addFile("file2.txt");

    // ���������� ������ ������
    manager.addVersion("file1.txt", FileVersion(1, "2024-03-20", true));
    manager.addVersion("file1.txt", FileVersion(2, "2024-03-21", false));
    manager.addVersion("file2.txt", FileVersion(1, "2024-03-20", true));
    manager.addVersion("file2.txt", FileVersion(2, "2024-03-21", true));

    // ��������� ���������� � ������� ������
    manager.printAllFileVersions("file1.txt");
    manager.printAllFileVersions("file2.txt");

    // ���������� ������������ ���������� �� ���� ������, ������ ������ � ��������� ������
    manager.printConfigurationsByDate("2024-03-20");
    manager.printConfigurationByVersion(2);
    manager.printConfigurationsByState(true);

    return 0;
}
