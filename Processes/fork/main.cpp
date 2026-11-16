#include <cerrno>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>

#include <unistd.h>
#include <sys/wait.h>

int main() {
    int value {42};
    std::cout << "Before fork: PID " << getpid() << ", value = " << value << std::endl;

    pid_t childPid {fork()};
    if (childPid == -1) {
        // No child was created. We must not enter either execution branch.
        std::perror("fork");
        return 1;
    }

    // Both processes continue here, but fork returned a different value to each.
    // They have separate memory, initially containing the same value of 42.
    if (childPid == 0) {
        value = 99; // Change only the child's copy.
        std::cout << "Child: PID " << getpid()
                  << ", fork returned " << childPid
                  << ", value = " << value << std::endl;

        // Pause only to give us time to inspect the processes using ps.
        std::this_thread::sleep_for(std::chrono::seconds(10));

        // Replace the child's program with ls. The parent keeps running ours.
        // Successful exec never returns, so ls supplies the child's exit status.
        execl("/bin/ls", "ls", "-l", static_cast<char*>(nullptr));

        // We reach this line ONLY if exec failed. Report the error and terminate
        // the child with a nonzero status, without normal C++/stream cleanup.
        std::perror("execl");

        // Child processes should always use _exit to quit, instead of return. Otherwise they might release a resource
        // jointly owned by the two processes.
        _exit(1);
    }
    else {
        std::cout << "Parent: PID " << getpid()
                  << ", fork returned child PID " << childPid << std::endl;

        // There's no guarantee whether the child or parent will run first. If a parent needs the child to finish
        // before it continues, then it must use the waitpid() function.
        int childStatus {};
        if (waitpid(childPid, &childStatus, 0) == -1) {
            std::perror("waitpid");
            return 1;
        }

        // Waiting also collects the child's termination status. We will decode
        // childStatus in the statuscode example; completion alone is not success.
        std::cout << "Parent after waiting: value = " << value
                  << " (the child's change did not affect it)" << std::endl;
        std::cout << "Goodbye, world!" << std::endl;
    }
    return 0;
}
