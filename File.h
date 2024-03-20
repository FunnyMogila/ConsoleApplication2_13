#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include "FileVersion.h"

class File {
private:
    std::string name;
    std::vector<FileVersion> versions;

public:
    File(const std::string& filename);

    void addVersion(const FileVersion& version);

    std::string getName() const;
    void printAllVersions() const;

    std::vector<FileVersion> getVersionsByDate(const std::string& date) const;
    FileVersion getVersionByNumber(int num) const;
    std::vector<FileVersion> getFixedVersions() const;
    std::vector<FileVersion> getVersionsByState(bool isFixed) const; // Добавленный метод
};

#endif // FILE_H

