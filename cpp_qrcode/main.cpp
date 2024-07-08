#include <iostream>
#include <fstream>
#include <curl/curl.h>

std::string token = "tTZI+3AKQRl/BdenDNP6Ag==4Pf6YJH68GQG3HR5";
int i = 0;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::ostream& stream) {
    return stream.write(static_cast<char*>(contents), size * nmemb).fail() ? 0 : size * nmemb;
}

std::string genertrate_filename()
{
    std::string filename = "img-";
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
        filename += std::to_string(rand() % 100000);

    filename += ".png";
    i++;
    return filename;
}

int main() {
    std::string data = "0";
    std::cout << "Enter data that you want to convert to QR code: ";
    std::getline(std::cin, data);
    std::string fmt = "png";
    std::string api_url = "https://api.api-ninjas.com/v1/qrcode?data=" + data + "&format=" + fmt;

    CURL* curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        std::string filename = genertrate_filename();
        std::ofstream out_file(filename, std::ofstream::binary);

        curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out_file);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, NULL); 
        curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("X-Api-Key: " + token).c_str());
        headers = curl_slist_append(headers, "Accept: image/png");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        else 
            std::cout << "Success!" << std::endl;
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);

        out_file.close();
    } else {
        std::cerr << "Error initializing CURL." << std::endl;
    }
    return 0;
}
