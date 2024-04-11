#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "FileVersion.h"

class Item {
protected:
    std::string name;
    std::vector<FileVersion> versions;

public:
    Item(const std::string& name);
    void addVersion(const FileVersion& version);
    std::string getName() const;
    void printAllVersions() const;
};

#endif // ITEM_H
