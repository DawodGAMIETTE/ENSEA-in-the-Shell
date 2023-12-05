#include <stdio.h>
//#include <bits/syscall.h>
#include <sys/syscall.h>
#include <unistd.h>

int main() {

    syscall(SYS_write,1,"Bienvenue dans le Shell ENSEA\n",30);
    syscall(SYS_write,1,"Pour quitter, tapez 'exit'.\n",28);

    //printf("Hello, World!\n");
    //scanf("press exit");
    return 0;

}
