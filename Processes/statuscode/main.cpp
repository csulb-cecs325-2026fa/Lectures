#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/wait.h>

// This program uses curl to download a file, then continues once the download is complete.
int main(int argc, char* argv[])
{
    std::cout << "Starting curl" << std::endl;
    // Download a file with curl, then do something with it.
    int cid {fork()};
    if (cid == 0) {
        std::cout << "Starting download..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        // Child process. Run curl.
        execl("/bin/curl",
            "curl",
            "-L",
            "-o",
            "demo.cpp",
            "https://drive.google.com/uc?export=download&id=17vxURsbI0ubvgERu9vejsaTkTooIOhCS",
            static_cast<char*>(nullptr));
    }
    else {
        int statusCode;
        std::cout << "Waiting for download..." << std::endl;
        waitpid(cid, &statusCode, 0);
        if (statusCode == 0) {
            std::cout << "Download was a success" << std::endl;

            // Do something with the file here.


            return 0;
        }
        else {
            std::cout << "curl failed with code " << statusCode << std::endl;
            return -1;
        }
    }
}
