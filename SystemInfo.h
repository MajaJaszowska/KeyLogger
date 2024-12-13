#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <string>

class SystemInfo {
protected:
    std::string username;
    std::string computer_id;
    std::string OSversion;


    void CollectSystemInfo();


    friend class RaportMaker;

public:
    SystemInfo();
    ~SystemInfo();

    std::string GetUserName1() const;
    std::string GetComputerID1() const;
    std::string GetOSVersion() const;

};

#endif // SYSTEMINFO_H
