#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <pthread.h>

#define MAX_THRDS 4 //numero de processadores

#define max 1000 //tam. max. arquivo

int a[max][max], b[max][max], c[max][max];

int n,nprocs;

void readdata()

{

    int i,j;

    FILE *fpa,*fpb;

    /* read matrix a */

    fpa = fopen("a","r");

    for (i=0; i < n; i++)

        for (j=0; j < n; j++)

        fscanf(fpa,"%f", &a[j]);

    fclose(fpa);

    /* read matrix b */

    fpb = fopen("b","r");

    for (i=0; i < n; i++)

        for (j=0; j < n; j++)

        fscanf(fpb,"%f", &b[j]);

    fclose(fpb);

}

void printdata()

{

    int i,j;

    FILE *fpc;

    /* write results */

    fpc = fopen("thread_c","w");

    for (i=0; i < n; i++)

        for (j = 0; j < n; j++)

        fprintf(fpc,"%f\n",c[j]);

    fclose(fpc);

}

void matmul(int *num_thread) //funcao que multiplica..threads a chamam.

{

    int i, j, k;

    int iprocs, jprocs;

    int my_id, i_id,j_id,ilb,iub,jlb,jub;

    /* number of processors in i direction */

    iprocs = (int) sqrt((double) nprocs);

    /* number of processors in j direction */

    printf("n:%d\n", *num_thread);
    pthread_exit (NULL);

}

int main(int argc, char **argv) {

    pthread_t t[MAX_THRDS];

    pthread_attr_t attr;

    int param;

    int i;

    void readdata(),matmul(),printdata();

    //inicializacao das threads

    pthread_attr_init(&attr);

    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);

    /* get n and nprocs parameters */

    if (argc != 3) {
        printf("usage: pth_matrix <size of matrices> <number of processors>\n");

        exit(1);
    }

    n = atoi(argv[1]);

    nprocs = atoi(argv[2]);

    /* reads matrix a and b */

    readdata();

    /* create threads */

    for (i=0; i < nprocs; i++) {
        param=i;

        pthread_create(&t, &attr, (void *)matmul, &param);
    }

    /* wait termination of created threads */

    for (i=0; i < nprocs; i++)
        pthread_join(t, NULL);

    /* outputs matrix c */

    printdata();

    return (0);

}