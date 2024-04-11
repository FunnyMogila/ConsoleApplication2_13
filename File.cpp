#include "File.h"

File::File(const std::string& filename) : Item(filename) {}

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

std::vector<FileVersion> File::getVersionsByDate(const std::string& date) const {
    std::vector<FileVersion> result;
    for (const auto& version : versions) {
        if (version.getDate() == date) {
            result.push_back(version);
        }
    }
    return result;
}

