#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>

int main() {
    char *buff = NULL;
    while()
    while (1) {
        read(0,buff,4);
        write(1,"salut",5);
        if (buff!=0){
            syscall(SYS_write,1,&buff,4);
        }
        void *buf;
        //read(-1, buff, 100);
        //write(0,buff,4);

        //syscall(SYS_read, 1, buff);
        //write(0,"bon",3);
        return 0;
    }
}