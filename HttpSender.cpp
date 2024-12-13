#include "HttpSender.h"
#include <iostream>
#include <curl/curl.h>

void SendFileHttp(const std::string &file_to_send)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_mime *form = curl_mime_init(curl);
        curl_mimepart *place = curl_mime_addpart(form);

        curl_mime_name(place, "fileToUpload");
        curl_mime_filedata(place, file_to_send.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/upload_test/upload.php");
        curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

        //TESTOWANIE
        res = curl_easy_perform(curl);
        if( res != CURLE_OK ) {
            std::cerr << "Jest blad " << file_to_send << ": " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Plik " << file_to_send << " wyslano" << std::endl;
        }

        curl_mime_free(form);
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "libcurl nie dziala" << std::endl;
    }

    curl_global_cleanup();
}
