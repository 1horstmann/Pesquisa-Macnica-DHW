#include <iostream>
#include <string>
#include <C:\curl\curl.h>

static size_t WriteCallBack(char *contents, size_t size, size_t nmemb, char *buffer_int){
    ((std::string*)buffer_int)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


int main(){
    CURL *curl;

    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl){

        curl_easy_setopt(curl, CURLOPT_URL, "http://www.crawlerweb.com.br/template/tpm.js1.php");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        
        curl_easy_cleanup(curl);
    }

}
