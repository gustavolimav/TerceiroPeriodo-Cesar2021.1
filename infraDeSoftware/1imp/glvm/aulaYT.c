#include "fun.h"
#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Int")

int main(int argc, char const *argv[]) {   
    int lines1, coluns1, lines2, coluns2;
	FILE *fp, *out;
	clock_t time;

	fp = fopen(argv[1], "r");
	if (!fp) {
		printf("Error: First file does not exist\n");
		return 1;
	}

	lines1 = linhas(fp);
	fseek(fp, 0, SEEK_SET);

	coluns1 = colunas(fp, lines1);
	fseek(fp, 0, SEEK_SET);

	if (coluns1 == -1) { // review this
		printf("Error: First matrix is invalid\n");
		fclose(fp);
		return 1;
	}

	int fst[lines1][coluns1];
	scan_matrix(fp, lines1, coluns1, fst);
	
	fclose(fp);

	fp = fopen(argv[2], "r");

	if (!fp) {
		printf("Error: Second file does not exist\n");
		return 1;
	}

	lines2 = linhas(fp);
	fseek(fp, 0, SEEK_SET);

	coluns2 = colunas(fp, lines2);
	fseek(fp, 0, SEEK_SET);

	if (coluns2 == -1) { // review this
		printf("Error: Second matrix is invalid\n");
		fclose(fp);
		return 1;
	}

	int fst2[lines2][coluns2];

	scan_matrix(fp, lines2, coluns2, fst2);

	int pid, filho = 0;
	int lines3 = lines1 * lines2, coluns3 = coluns1 * coluns2;
	int total = lines3 * coluns3;

	char (*fst4)[2];
	const char *name = "Matrix_fst3";
	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, total);
	fst4 = (char(*)[2])mmap(0, total,  PROT_WRITE,   MAP_SHARED,  shm_fd, 0);

	for (int k = 0; k < 4; k++) {
		if (pid != 0) {
			filho+=1;
			pid = fork();
		}
		if (pid == 0) {
			// forkeado(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst4, n);
			int col, row, flag = 0, n = 0;
			int total = lines3 * coluns3;

			for(int l = 0; l < lines1; l++) { //0
				for(int c = 0; c < coluns1; c++) { //0
					row = 0;
					for(int l2 = 0; l2 < lines2; l2++) {
						col = 0;
						for(int c2 = 0; c2 < coluns2; c2++) {
							if (filho == 1 && n < total/4) { //fork(1)
								fst4[row][col] = fst[l][c] * fst2[l2][c2];
								flag = 1;
							}
							else if (filho == 2 && n >= total/4 && n < (total/4)*2) { //fork(2)
								fst4[row][col + (coluns3/2)] = fst[l][c] * fst2[l2][c2];
								flag = 1;
							}
							else if (filho == 3 && n >= (total/4)*2 && n < (total/4)*3) {
								fst4[row + (lines3/2)][col] = fst[l][c] * fst2[l2][c2]; //fork(3)
								flag = 1;
							}
							else {
								fst4[row + (lines3/2)][col + (coluns3/2)] = fst[l][c] * fst2[l2][c2]; //fork(4)
								flag = 1;
							}
							col+=1;
							n++;
						}
						row+=1;
					}
					if(flag == 1) {
						exit(0);
					}
				}
			}
			exit(0);
		}
		wait(NULL);	
	}
	out = fopen("tensor_glvm.out", "w");

	for (int a = 0; a < lines3; a++) {
		for (int b = 0; b < coluns3; b++)
			printf( "%d ", fst4[a][b]);
		printf( "%s", "\n");
	}
	
	fclose(out);
	fclose(fp);

	// consumer(name, SIZE, ptr);

    return 0;
}
