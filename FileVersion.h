#ifndef FILE_VERSION_H
#define FILE_VERSION_H

#include <string>

class FileVersion {
private:
    int number;
    std::string date;
    bool isFixed;

public:
    FileVersion(int num, const std::string& dt, bool fixed);

    int getNumber() const;
    std::string getDate() const;
    bool isFixedVersion() const;

    void fixVersion();
    void editVersion();
};

#endif // FILE_VERSION_H
