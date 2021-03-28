#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    int col;
    int row;
    int id;
    int value;
}thread_arg, *ptr_thread_arg;

pthread_t threads[4];

void *thread_func(void *arg) {
    // ptr_thread_arg targ = (ptr_thread_arg)arg;
    int *i = (int *)arg;

    printf("%d\n", *i);

    // int fst1[2][5] = {2,2,2,2,2,2,2,2,2,2};
    // int fst2[5][2] = {1,1,1,1,1,1,1,1,1,1};
    // int fst3[10][10];
    // int lines3 = targ->row, coluns3 = targ->col, lines1 = 2, lines2 = 5, coluns2 = 2, coluns1 = 5;
	// int col, row, flag = 0, n = 0;
    
	// 		int total = lines3 * coluns3;
	// 		for(int l = 0; l < lines1; l++) { //0
	// 			for(int c = 0; c < coluns1; c++) { //0
	// 				row = l * lines2;
	// 				for(int l2 = 0; l2 < lines2; l2++) {
	// 					col = c * coluns2;
	// 					for(int c2 = 0; c2 < coluns2; c2++) {
	// 						if (targ->id == 1 && (n < total/4)) { //fork(1)
	// 							fst3[row][col] = fst1[l][c] * fst2[l2][c2];
	// 							flag = 1;
	// 						}
	// 						else if (targ->id == 2 && (n >= total/4)  && (n < (total/4)*2)) { //fork(2)
	// 							fst3[row][col] = fst1[l][c] * fst2[l2][c2];
	// 							flag = 1;
	// 						}
	// 						else if (targ->id == 3 && (n >= (total/4)*2) && (n < (total/4)*3)) {
	// 							fst3[row][col] = fst1[l][c] * fst2[l2][c2]; //fork(3)
	// 							flag = 1;
	// 						}
	// 						else if (targ->id == 4 && (n >= (total/4)*3) && (n < total)) {
	// 							fst3[row][col] = fst1[l][c] * fst2[l2][c2]; //fork(4)
	// 							flag = 1;
	// 						}
	// 						col++;
	// 						n++;
	// 					}
	// 					row++;
	// 				}
	// 			}
	// 		}
      return 0;
}

int main(int argc, char **argv) {
    thread_arg arguments[4];
    int i;
    
    for(i = 0; i < 4; i++) {
        arguments[i].row = 10;
        arguments[i].col = 10;
        arguments[i].id = i + 1;
        pthread_create(&(threads[i]), NULL, thread_func, &(arguments[i]));
        pthread_join(threads[i], NULL);
    }


}