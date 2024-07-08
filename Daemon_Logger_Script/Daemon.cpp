#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cctype>

#include <fcntl.h>

using namespace std;

void daemonize() {
    pid_t pid = fork();

    if (pid > 0) {
        cout << "Parent process exiting..." << endl;
        exit(EXIT_SUCCESS);
    }
    umask(0);
    pid_t sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDERR_FILENO);
}

int main() {
    daemonize();
        int fd = open("/Your/PATH/FILE.TXT", O_WRONLY | O_CREAT, 0644);
        if (fd < 0) {
            exit(EXIT_FAILURE);
        }
    while (true) {
        char key = getchar();
        if (isprint(key) != 0)
        {
            printf("it is printable\n");
            write(fd, &key, 1);
             fsync(fd); 
        }
        else 
        {
            usleep(1);
        }
    }

    return 0;
}
