#include "FileVersion.h"

FileVersion::FileVersion(int num, const std::string& dt, bool fixed) : number(num), date(dt), isFixed(fixed) {}

int FileVersion::getNumber() const {
    return number;
}

std::string FileVersion::getDate() const {
    return date;
}

bool FileVersion::isFixedVersion() const {
    return isFixed;
}

void FileVersion::fixVersion() {
    isFixed = true;
}

void FileVersion::editVersion() {
    isFixed = false;
}

