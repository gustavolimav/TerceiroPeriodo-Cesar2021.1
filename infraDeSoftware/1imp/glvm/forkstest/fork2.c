#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t filho;
    int status;

    filho = fork();

    if (filho == 0) //código do filho
    {
        printf("Sou o processo filho.\n");
        for (int i = 0; i < 5; i++) {
            printf("%d\n", i);
            sleep(2);
        }
        _exit(0);
           
    }
    else if (filho > 0) { //código do pai
        wait(NULL);
        printf("Sou o pai. Agora eu posso executar meu código.\n");
    }
    return 0;
}

