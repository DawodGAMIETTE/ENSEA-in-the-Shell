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
    syscall(SYS_write,1,"Bienvenue dans le Shell ENSEA\n",30);
    syscall(SYS_write,1,"Pour quitter, tapez 'exit'.\n",28);

    pid_t ret = fork();

    if (ret == 0) {
        char name[20];
        while (1){
            write(1,"enseash % ", strlen("enseash % "));
            scanf("%s",&name);
            if(strcmp("exit",name)==0){ exit(1);}
            else{
                pid_t ret2=fork();
                char* begin;
                char* end;
                if (ret2==0){
                    write(1,name,strlen(name));
                    write(1,"  ",2);
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
