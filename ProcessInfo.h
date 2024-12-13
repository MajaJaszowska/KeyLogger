#ifndef PROCESSINFO_H
#define PROCESSINFO_H

#include "SystemInfo.h"
#include <string>

class ProcessInfo : public SystemInfo {
public:
    ProcessInfo();
    ~ProcessInfo();

    std::string GetRunningProcesses() const;
};

#endif // PROCESSINFO_H