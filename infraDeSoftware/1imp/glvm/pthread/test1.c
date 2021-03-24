#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int sum; /* esses dados são compartilhados pelo(s) thread(s) */
void *runner(void* fst); /* os threads chamam essa função */
int main(int argc, char *argv[])
{
    pthread_t tid; /* o identificador do thread */
    pthread_attr_t attr; /* conjunto de atributos do thread */
    if (argc != 2) {
        fprintf(stderr,"usage: a.out <integer value>\n");
        return -1;
    }
    if (atoi(argv[1]) < 0) {
        fprintf(stderr,"%d must be >= 0\n",atoi(argv[1]));
        return -1;
    }
    /* obtém os atributos default */
    pthread_attr_init(&attr);
    /* cria o thread */
    int fst[2][2] = {2,2,2,2};
    int* a = malloc((sizeof(int)));
    *a = fst[];
    pthread_create(&tid,&attr,runner,a);
    /* espera o thread ser encerrado */
    pthread_join(tid,NULL);
    printf("sum = %d\n",sum);
}
/* O thread assumirá o controle nessa função */
void *runner(void* fst) {
    int i, upper = atoi(fst);
    sum = 0;
    for (i = 1; i <= upper; i++)
        sum += upper;
    pthread_exit(0);
}
