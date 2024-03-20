#include "File.h"
#include <iostream>
#include <stdexcept>

File::File(const std::string& filename) : name(filename) {}

void File::addVersion(const FileVersion& version) {
    versions.push_back(version);
}

std::string File::getName() const {
    return name;
}

void File::printAllVersions() const {
    std::cout << "Versions of file " << name << ":\n";
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

std::vector<FileVersion> File::getVersionsByDate(const std::string& date) const {
    std::vector<FileVersion> result;
    for (const auto& version : versions) {
        if (version.getDate() == date) {
            result.push_back(version);
        }
    }
    return result;
}

FileVersion File::getVersionByNumber(int num) const {
    for (const auto& version : versions) {
        if (version.getNumber() == num) {
            return version;
        }
    }
    throw std::invalid_argument("Version number not found.");
}

std::vector<FileVersion> File::getFixedVersions() const {
    std::vector<FileVersion> result;
    for (const auto& version : versions) {
        if (version.isFixedVersion()) {
            result.push_back(version);
        }
    }
    return result;
}

std::vector<FileVersion> File::getVersionsByState(bool isFixed) const {
    std::vector<FileVersion> result;
    for (const auto& version : versions) {
        if (version.isFixedVersion() == isFixed) {
            result.push_back(version);
        }
    }
    return result;
}
