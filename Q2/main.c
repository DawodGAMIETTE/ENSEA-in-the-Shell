//
// Created by davigami29 on 07/12/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    pid_t ret = fork();

    if (ret == 0) {
        char name[20];
        while (1){
            scanf("%s",&name);
            if(strcmp("exit",name)==0){ exit(1);}
            else{
                pid_t ret2=fork();
                if (ret2==0){
                    execvp(name, NULL);
                }
                else{
                    wait(NULL);
                }
            }
            wait(NULL);
        }
    } else {
        wait(NULL);
    }
    return 0;
}

