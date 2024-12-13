#include "ProcessInfo.h"
#include <Windows.h>
#include <psapi.h>
#include <sstream>


ProcessInfo::ProcessInfo() : SystemInfo() {

}


ProcessInfo::~ProcessInfo() {

}

std::string ProcessInfo::GetRunningProcesses() const
{
    std::ostringstream process_info;

    DWORD process_ids[1024], process_count;

    EnumProcesses(process_ids, sizeof(process_ids), &process_count);
    process_count /= sizeof(DWORD); // /4


    process_info << "Uruchomione procesy:\n";

    for (int i=0 ; i<process_count ; i++)
        {

        if (process_ids[i] != 0)
            {
            HANDLE process_handle_ccos = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, process_ids[i]);

            if (process_handle_ccos)
            {
                TCHAR process_name[MAX_PATH] = TEXT("<puste>"); //char, max 260 (#define MAX_LETTER 513)
                DWORD bajt_need;
                HMODULE mod_lib_dll;


                if (EnumProcessModules(process_handle_ccos, &mod_lib_dll, sizeof(mod_lib_dll), &bajt_need)) //nullptr
                {

                    GetModuleFileNameEx(process_handle_ccos, mod_lib_dll, process_name, sizeof(process_name) / sizeof(TCHAR));

                }
                process_info << "PID: " << process_ids[i] << " - Nazwa procesu: " << process_name << "\n";

                CloseHandle(process_handle_ccos);
            }
        }
    }


    process_info << std::endl;

    return process_info.str();
}
