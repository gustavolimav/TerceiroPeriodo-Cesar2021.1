#include <pthread h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix, *matrix_ptr;

void *maxthread(void *arg) {   
    matrix_ptr m = (matrix_ptr)arg;

    for (int i = 0; i < m->rows; i++) {

        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = i * j;
        }
    }

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d\n", m->data[i][j]);
        }

        printf("\n");
    }

    printf("\n");
    return NULL;
}

int main() {   
    int num_threads = 3; // or take user input
    pthread_t threads[num_threads];
    matrix m[3];
    m->rows = 11;         // or take user input
    m->cols = 8;
    m->data = malloc(sizeof(int *) * m->rows);
    

    for (int i = 0; i < num_threads; i++) {
        pthread_t thread;
        m->data[i] = malloc(sizeof(int) * m->cols);
        pthread_create(&thread, NULL, maxthread, &(m[i]));
        threads[i] = thread;
        sleep(1);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }

    free(m->data);
    return 0;
}