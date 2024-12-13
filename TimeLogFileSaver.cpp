#include "TimeLogFileSaver.h"
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "KeyRepresentation.h"


TimeLogFileSaver::TimeLogFileSaver(const std::string& normalFile)
    : FileSaver(normalFile) {
}

void TimeLogFileSaver::SaveNormal(const int keyPressNumber) {
    std::ofstream logs_time;
    logs_time.open(NameFile_infotxt, std::ios_base::app);

    std::string TimeDataWriter = GetTime_Date_Data();
    logs_time << TimeDataWriter << " : " << GetKeyRepresentation(keyPressNumber) << std::endl;
    logs_time.close();
}


std::string TimeLogFileSaver::GetTime_Date_Data() {
    auto t = std::time(nullptr);
    auto tbuff = *std::localtime(&t);

    std::ostringstream DateTime_Stream;
    DateTime_Stream << std::put_time(&tbuff, "%Y-%m-%d %H:%M:%S");

    return DateTime_Stream.str();
}
