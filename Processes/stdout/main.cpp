#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

// This program redirects the standard output stream of a child process to save to a file, instead
// of printing to the console.
int main()
{
    std::cout << "Starting curl" << std::endl;
    // Download a file with curl, then do something with it.
    int cid {fork()};
    if (cid == 0) {
        std::cout << "Starting download..." << std::endl;

        // Open a new file to store the standard output and standard error streams of the
        // child process.
        // This is a C function to open a file, and get back a "file descriptor" -- a unique integer ID
        // to utilize the file.
        int outputFile {open("demo_output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)};
        // dup2: a system call to replace a process's standard input/output streams
        // with a file.
        dup2(outputFile, STDOUT_FILENO); // replace standard out with the outputFile.
        dup2(outputFile, STDERR_FILENO); // replace standard error with the outputFile.

        // Because this doesn't run in the parent process, the parent's output still goes to
        // the console (standard out).

        // Child process. Run curl.
        if (execl("/bin/curl",
            "curl",
            "-L",
            "-o",
            "demo.cpp",
            "https://drive.google.com/uc?export=download&id=17vxURsbI0ubvgERu9vejsaTkTooIOhCS",
            static_cast<char*>(nullptr)) < 0) {
            std::cout << "Couldn't exec curl" << std::endl;
        }
    }
    else {
        int statusCode;
        // The parent process did NOT use dup2, so its standard output still goes to the console.
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
