#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int value = 5;
    pid_t pid;
    pid = fork();
    if (pid == 0) { /* processo-filho */
        value += 15;
        return 0;
    }
    else if (pid > 0) { /* processo-pai */
        wait(NULL);
        printf("parent value= %d \n",value); /* LINHA A */
        return 0;
    }
}
