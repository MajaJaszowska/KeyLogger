#ifndef FILESAVER_H
#define FILESAVER_H

#include <string>

class FileSaver {
protected:
    std::string NameFile_infotxt;


public:

    FileSaver(const std::string& normalFile);

    virtual void SaveNormal(const int keyPressNumber) = 0;
};

#endif  // FILESAVER_H
