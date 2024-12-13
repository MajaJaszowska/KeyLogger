#include "SystemInfo.h"
#include <Windows.h>
#include <Lmcons.h>
#include <psapi.h>
#include <sstream>


void SystemInfo::CollectSystemInfo() {

    char username_buf[256];
    DWORD username_dlg = 256; //unsigned int

    if (GetUserNameA(username_buf, &username_dlg))
        {
        username = std::string(username_buf);

    }
    else
        {
        username = "Nie da sie okreslic";
    }



    char computer_name_buf[256];
    DWORD compname_dlg = 256;

    if (GetComputerNameA(computer_name_buf, &compname_dlg))
        {
        computer_id = std::string(computer_name_buf);
    }
    else
        {
        computer_id = "Nie da sie okreslic";
    }


    OSVERSIONINFO versi_os;
    versi_os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    if (GetVersionEx(&versi_os))
        {
        std::ostringstream version;
        
        version << "Windows " << versi_os.dwMajorVersion << "." << versi_os.dwMinorVersion;
        OSversion = version.str();
    }
    else
        {
        OSversion = "Nie da sie okreslic wersji";
    }

}


SystemInfo::SystemInfo() {
    CollectSystemInfo();
}


SystemInfo::~SystemInfo() {

}


std::string SystemInfo::GetUserName1() const {
    return username;
}

std::string SystemInfo::GetComputerID1() const {
    return computer_id;
}

std::string SystemInfo::GetOSVersion() const {
    return OSversion;
}


