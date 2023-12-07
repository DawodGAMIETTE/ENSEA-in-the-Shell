#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>

int main(int argc,char *argv[]) {
    char* command=argv[1];
    pid_t ret = fork();
    if (ret == 0) {
        //write(1, "Je suis le fils\n", strlen("Je suis le fils\n"));
        execvp(command, NULL);
    } else {
        wait(NULL);
    }
    return 0;
}
