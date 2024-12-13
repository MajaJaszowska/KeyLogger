#ifndef RAPORTMAKER_H
#define RAPORTMAKER_H

#include <map>
#include <string>

class RaportMaker {
private:
    std::string ReportNameFile_infotxt;
    bool SystemInfoWritten;

    void InitializeReport();
    void WriteSystemInfo();

public:
    RaportMaker(const std::string& report_filename);
    ~RaportMaker();

    void SaveReport(const std::map<std::string, int>& KeyPressCountMap);

};

#endif // RAPORTMAKER_H
