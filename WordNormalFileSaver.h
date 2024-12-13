#ifndef WORDNORMALFILESAVER_H
#define WORDNORMALFILESAVER_H

#include "FilesSaver.h"
#include <string>

class WordNormalFileSaver : public FileSaver {
public:

    WordNormalFileSaver(const std::string& normalFile);


    void SaveNormal(const int keyPressNumber);
};

#endif  // WORDNORMALFILESAVER_H