#include "Item.h"
#include <iostream>

Item::Item(const std::string& name) : name(name) {}

void Item::addVersion(const FileVersion& version) {
    versions.push_back(version);
}

std::string Item::getName() const {
    return name;
}

void Item::printAllVersions() const {
    std::cout << "Versions of item " << name << ":\n";
    for (const auto& version : versions) {
        std::cout << "Version " << version.getNumber() << ", Date: " << version.getDate();
        if (version.isFixedVersion()) {
            std::cout << " (Fixed)\n";
        }
        else {
            std::cout << " (Editing)\n";
        }
    }
}
