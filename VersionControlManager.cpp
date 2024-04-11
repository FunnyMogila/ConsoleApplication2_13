#include "VersionControlManager.h"
#include <iostream>
#include <stdexcept>

void VersionControlManager::addFile(const std::string& filename) {
    files.emplace_back(filename);
}

File* VersionControlManager::getFileByName(const std::string& filename) {
    for (auto& file : files) {
        if (file.getName() == filename) {
            return &file;
        }
    }
    return nullptr;
}

void VersionControlManager::addVersion(const std::string& filename, const FileVersion& version) {
    File* file = getFileByName(filename);
    if (file) {
        file->addVersion(version);
    }
    else {
        std::cerr << "File not found.\n";
    }
}

void VersionControlManager::printAllFileVersions(const std::string& filename) {
    File* file = getFileByName(filename);
    if (file) {
        file->printAllVersions();
    }
    else {
        std::cerr << "File not found.\n";
    }
}

void VersionControlManager::printConfigurationsByDate(const std::string& date) {
    std::cout << "Configurations by date " << date << ":\n";
    for (auto& file : files) {
        auto versions = file.getVersionsByDate(date);
        if (!versions.empty()) {
            std::cout << "File: " << file.getName() << "\n";
            for (const auto& version : versions) {
                std::cout << "Version " << version.getNumber() << "\n";
            }
        }
    }
}

void VersionControlManager::printConfigurationByVersion(int num) {
    std::cout << "Configuration by version number " << num << ":\n";
    for (auto& file : files) {
        try {
            auto version = file.getVersionByNumber(num);
            std::cout << "File: " << file.getName() << ", Version: " << version.getNumber() << "\n";
        }
        catch (const std::invalid_argument& e) {
            // Version number not found for this file
        }
    }
}

void VersionControlManager::printConfigurationsByState(bool isFixed) {
    std::cout << "Configurations by state:\n";
    for (auto& file : files) {
        auto versions = isFixed ? file.getFixedVersions() : file.getVersionsByState(isFixed);
        if (!versions.empty()) {
            std::cout << "File: " << file.getName() << "\n";
            for (const auto& version : versions) {
                std::cout << "Version " << version.getNumber() << "\n";
            }
        }
    }
}



