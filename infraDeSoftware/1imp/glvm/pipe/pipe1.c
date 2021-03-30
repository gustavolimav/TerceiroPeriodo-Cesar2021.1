#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main () {

    int fd[2];
    int fd2[2];
    int fd3[2];
    int fd4[2];
    int matrix[2][2];
    int n;

    pipe (fd);

    int pid = fork();

    if (pid == 0) {
        close(fd[0]);
        printf ("Start child process with pid: %d\n", pid);
        matrix[0][0] = 2;
        write (fd[1], matrix, 4*sizeof(int));
        close(fd[1]);
    }
    pipe(fd2);
    if (pid != 0) {
        pid = fork();
        if (pid == 0) {
            close(fd2[0]);
            close(fd[1]);
            printf ("Start child process with pid: %d\n", pid);
            read(fd[0], matrix, sizeof(int)*4);
            matrix[1][1] = 1;
            write (fd2[1], matrix, 4*sizeof(int));
            close(fd2[1]);
            close(fd[0]);
        }
    }
    pipe(fd3);
    if (pid != 0) {
        pid = fork();
        if (pid == 0) {
            close(fd3[0]);
            close(fd2[1]);
            printf ("Start child process with pid: %d\n", pid);
            read(fd2[0], matrix, sizeof(int)*4);
            matrix[1][0] = 3;
            write (fd3[1], matrix, 4*sizeof(int));
            close(fd3[1]);
            close(fd2[0]);
        }
    }
    pipe(fd4);
    if (pid != 0) {
        pid = fork();
        if (pid == 0) {
            close(fd4[0]);
            close(fd3[1]);
            printf ("Start child process with pid: %d\n", pid);
            read(fd3[0], matrix, sizeof(int)*4);
            matrix[0][1] = 7;
            write (fd4[1], matrix, 4*sizeof(int));
            close(fd4[1]);
            close(fd3[0]);
        }
    }
    
    if (pid != 0) {
        close(fd4[1]);

        read(fd4[0], matrix, sizeof(int)*4);

        printf("%d %d\n%d %d", matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);

        close(fd4[0]);
    }

return 0;
}