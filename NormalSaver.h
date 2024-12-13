#ifndef NORMALSAVER_H
#define NORMALSAVER_H

#include "FilesSaver.h"
#include <fstream>

class NormalSaver : public FileSaver {
public:

    NormalSaver(const std::string& normalFile);


    void SaveNormal(const int keyPressNumber);
};

#endif  // NORMALSAVER_H
