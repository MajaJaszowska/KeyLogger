#ifndef TIMELOGFILESAVER_H
#define TIMELOGFILESAVER_H

#include "FilesSaver.h"

class TimeLogFileSaver : public FileSaver {

public:
    TimeLogFileSaver(const std::string& normalFile);

    void SaveNormal(const int keyPressNumber);

protected:

    std::string GetTime_Date_Data();
};

#endif  // TIMELOGFILESAVER_H
