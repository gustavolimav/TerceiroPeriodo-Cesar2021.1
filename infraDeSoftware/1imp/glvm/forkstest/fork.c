#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
    /* o tamanho (em bytes) do objeto de memória compartilhada */
    const int SIZE = 4096;
    /* nome do objeto de memória compartilhada */
    const char *name = "OS";
    /* strings gravadas na memória compartilhada */
    const char *message_0 = "Hello";
    const char *message_1 = "World!";
    /* descritor de arquivo da memória compartilhada */
    int shm_fd;
    /* ponteiro para o objeto de memória compartilhada */
    void *ptr;
    /* cria o objeto de memória compartilhada */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    /* configura o tamanho do objeto de memória compartilhada */
    ftruncate(shm_fd, SIZE);
    /* mapeia o objeto de memória compartilhada para a memória */
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    /* grava no objeto de memória compartilhada */
    sprintf(ptr,"%s",message_0);
    ptr += strlen(message_0);
    sprintf(ptr,"%s",message_1);
    ptr += strlen(message_1);
    return 0;
}