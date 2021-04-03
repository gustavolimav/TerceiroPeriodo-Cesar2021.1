#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int xrow;
int xcol;

int fst1[10000][10000];
int fst2[10000][10000];
int fst3[10000][10000];
int filhox = 0;

pthread_t threads[4];

void *thread_func(void *arg) {
    int lines3 = xrow, coluns3 = xcol, lines1 = 2, lines2 = 2, coluns2 = 2, coluns1 = 2;
	int col, row, flag = 0, n = 0;
			int total = lines3 * coluns3;
			for(int l = 0; l < lines1; l++) { //0
				for(int c = 0; c < coluns1; c++) { //0
					row = l * lines2;
					for(int l2 = 0; l2 < lines2; l2++) {
						col = c * coluns2;
						for(int c2 = 0; c2 < coluns2; c2++) {
							if (filhox == 1 && (n < total/4)) { //fork(1)
								fst3[row][col] = fst1[l][c] * fst2[l2][c2];
								flag = 1;
							}
							else if (filhox == 2 && (n >= total/4)  && (n < (total/4)*2)) { //fork(2)
								fst3[row][col] = fst1[l][c] * fst2[l2][c2];
								flag = 1;
							}
							else if (filhox == 3 && (n >= (total/4)*2) && (n < (total/4)*3)) {
								fst3[row][col] = fst1[l][c] * fst2[l2][c2]; //fork(3)
								flag = 1;
							}
							else if (filhox == 4 && (n >= (total/4)*3) && (n < total)) {
								fst3[row][col] = fst1[l][c] * fst2[l2][c2]; //fork(4)
								flag = 1;
							}
							col++;
							n++;
						}
						row++;
					}
					if (flag == 1)
						return 0;
				}
			}
      return 0;
}

int main(int argc, char **argv) {
    int i = 0;

	xrow = 4;
	xcol = 4;

    for(i = 0; i < 4; i++) {
		filhox++;
        pthread_create(&(threads[i]), NULL, thread_func, argv);
        pthread_join(threads[i], NULL);
    }

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", fst3[i][j]);
		}
		printf("\n");
	}


}