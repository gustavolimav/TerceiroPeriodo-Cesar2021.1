#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>


int main(){

    char (*some_2D_array)[2];
    int shm_fd;
    const char *name = "OS";

    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, 2*2);

    some_2D_array = (char(*)[2])mmap(0, 2*2,  PROT_WRITE,   MAP_SHARED,  shm_fd, 0);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++){
            some_2D_array[i][j] = 1;
        }
    }
    int pid = fork();

    if (pid == 0) {
        some_2D_array[0][0] = 2;
    } else {
        wait(NULL);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++){
                printf("%d ",some_2D_array[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}