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
<<<<<<< HEAD
void *runner(void* fst); /* os threads chamam essa função */
=======
void *runner(void *param); /* os threads chamam essa função */
>>>>>>> abe0456efc80ee971359f522ad4ce98c7df82ca1
int main(int argc, char *argv[])
{
    pthread_t tid; /* o identificador do thread */
    pthread_attr_t attr; /* conjunto de atributos do thread */
    FILE *fp;
    char texto_str[4000];
    
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
<<<<<<< HEAD
    int fst[2][2] = {2,2,2,2};
    int* a = malloc((sizeof(int)));
    *a = fst[];
    pthread_create(&tid,&attr,runner,a);
=======

    pthread_create(&tid,&attr,runner,argv[1]);
>>>>>>> abe0456efc80ee971359f522ad4ce98c7df82ca1
    /* espera o thread ser encerrado */
    fp = fopen(argv[1], "w");
    while(fgets(texto_str, 20, fp) != NULL)
    printf("%s", texto_str);
    fclose(fp);
    pthread_join(tid,NULL);
    printf("sum = %d\n",sum);
}
/* O thread assumirá o controle nessa função */
<<<<<<< HEAD
void *runner(void* fst) {
    int i, upper = atoi(fst);
    sum = 0;
    for (i = 1; i <= upper; i++)
        sum += upper;
=======
void *runner(void *param) {
    FILE *fp;
    char texto_str[4000];

    fp = fopen(param, "w");
    fclose(fp);
>>>>>>> abe0456efc80ee971359f522ad4ce98c7df82ca1
    pthread_exit(0);
}
