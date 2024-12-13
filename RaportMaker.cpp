#include "RaportMaker.h"
#include "SystemInfo.h"
#include "ProcessInfo.h"
#include <fstream>
#include <filesystem>
#include <ctime>
#include <iomanip>


RaportMaker::RaportMaker(const std::string& reportFileName)
    : ReportNameFile_infotxt(reportFileName), SystemInfoWritten(false) {
    InitializeReport();
}


RaportMaker::~RaportMaker() {}


void RaportMaker::InitializeReport() {
    if (std::filesystem::exists(ReportNameFile_infotxt)) {
        std::filesystem::remove(ReportNameFile_infotxt);
    }

    std::ofstream file(ReportNameFile_infotxt, std::ios::trunc);
    file.close();
}


void RaportMaker::WriteSystemInfo() {
    if (!SystemInfoWritten) {
        std::ofstream file_raport_add(ReportNameFile_infotxt, std::ios_base::app);

        std::time_t t = std::time(nullptr);
        char time_buffer[80];
        std::strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&t));

        SystemInfo sysInfo;

        file_raport_add << "Raport z klawiatury - Czas: " << time_buffer << "\n";

        file_raport_add << "Uzytkownik: " << sysInfo.GetUserName1() << "\n";
        file_raport_add << "Nazwa maszyny: " << sysInfo.GetComputerID1() << "\n";
        file_raport_add << "Wersja OS: " << sysInfo.GetOSVersion() << "\n"<<"\n";


        file_raport_add.close();
        SystemInfoWritten = true;
    }
}


void RaportMaker::SaveReport(const std::map<std::string, int>& KeyPressCountMap) {
    std::ofstream file_raport_add;
    file_raport_add.open(ReportNameFile_infotxt, std::ios_base::app);

    WriteSystemInfo();

    file_raport_add << "Wciśnięte klawisze:\n";
    for (const auto& pair : KeyPressCountMap) {
        file_raport_add << "Klawisz: " << pair.first << " : " << pair.second << " razy" << std::endl;
    }

    ProcessInfo Process_Info;
    file_raport_add << "\n" << Process_Info.GetRunningProcesses();

    file_raport_add.close();
}


