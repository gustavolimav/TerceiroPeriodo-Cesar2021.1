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

pthread_t threads[4];
int sum; /* esses dados são compartilhados pelo(s) thread(s) */
void *runner(void* param); /* os threads chamam essa função */

int main(int argc, char *argv[])
{
    pthread_t tid; /* o identificador do thread */
    pthread_attr_t attr; /* conjunto de atributos do thread */
    FILE *fp;
    char texto_str[4000];

    pthread_attr_init(&attr);
    for (int i = 0; i < 4; i++) {
        pthread_create(&tid,&attr,runner, argv[1]);
    }
    for (int j = 0; j < 4; j++)
        pthread_join(tid,NULL);
    printf("sum = %d\n",sum);
}
/* O thread assumirá o controle nessa função */
void *runner(void *param) {
    FILE *fp, *fp2, *fp3;

    fp = fopen("m1.txt", "w");
    fp2 = fopen("m2.txt", "w");
    fp3 = fopen("m3.txt", "w");

    printf("%d\n", pthread_self());

    for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++)
			fprintf(fp3, "%d ", 1);
		fprintf(fp3, "%s", "\n");
	}

    fclose(fp3);
    fclose(fp);
    fclose(fp2);
    pthread_exit(0);
}
