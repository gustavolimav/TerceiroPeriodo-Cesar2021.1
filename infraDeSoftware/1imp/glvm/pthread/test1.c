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
void *runner(void *param); /* os threads chamam essa função */
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

    pthread_create(&tid,&attr,runner,argv[1]);
    /* espera o thread ser encerrado */
    fp = fopen(argv[1], "w");
    while(fgets(texto_str, 20, fp) != NULL)
    printf("%s", texto_str);
    fclose(fp);
    pthread_join(tid,NULL);
    printf("sum = %d\n",sum);
}
/* O thread assumirá o controle nessa função */
void *runner(void *param) {
    FILE *fp;
    char texto_str[4000];

    fp = fopen(param, "w");
    fclose(fp);
    pthread_exit(0);
}
