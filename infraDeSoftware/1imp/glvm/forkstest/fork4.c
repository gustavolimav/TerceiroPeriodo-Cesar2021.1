#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main () {
    int i, pid;
    for (i = 0; i < 10; ++i) {
        pid = fork();
        if (pid != 0) { //se sou o processo filho: saio do ciclo!
            break;
        }
    }
    printf("I am : (i=%d),(pid=%d) mypid=%d\n",i, pid, getpid());
    wait(NULL);
    return 0;
}