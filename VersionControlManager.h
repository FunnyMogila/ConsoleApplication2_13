#ifndef VERSION_CONTROL_MANAGER_H
#define VERSION_CONTROL_MANAGER_H

#include <vector>
#include <string>
#include "File.h"

class VersionControlManager {
private:
    std::vector<File> files;

    File* getFileByName(const std::string& filename);

public:
    void addFile(const std::string& filename);
    void addVersion(const std::string& filename, const FileVersion& version);
    void printAllFileVersions(const std::string& filename);

    void printConfigurationsByDate(const std::string& date);
    void printConfigurationByVersion(int num);
    void printConfigurationsByState(bool isFixed);
};

#endif // VERSION_CONTROL_MANAGER_H
