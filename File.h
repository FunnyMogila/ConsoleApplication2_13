#ifndef FILE_H
#define FILE_H

#include "Item.h"
#include <stdexcept>

class File : public Item {
public:
    File(const std::string& filename);
    FileVersion getVersionByNumber(int num) const;
    std::vector<FileVersion> getFixedVersions() const;
    std::vector<FileVersion> getVersionsByState(bool isFixed) const;
    std::vector<FileVersion> getVersionsByDate(const std::string& date) const;
};

#endif // FILE_H

