#include "NormalSaver.h"
#include <fstream>
#include "KeyRepresentation.h"


NormalSaver::NormalSaver(const std::string& normalFile)
    : FileSaver(normalFile) {}



void NormalSaver::SaveNormal(const int keyPressNumber)  {
    std::ofstream logs_normal;
    logs_normal.open(NameFile_infotxt, std::ios_base::app);

    logs_normal << GetKeyRepresentation(keyPressNumber);
    logs_normal.close();
}
