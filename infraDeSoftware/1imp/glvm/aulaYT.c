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

	coluns1 = colunas(fp);
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

	coluns2 = colunas(fp);
	fseek(fp, 0, SEEK_SET);

	if (coluns2 == -1) { // review this
		printf("Error: Second matrix is invalid\n");
		fclose(fp);
		return 1;
	}

	int fst2[lines2][coluns2];

	scan_matrix(fp, lines2, coluns2, fst2);

	int pid, n = 0, lines3 = lines1 * lines2;
	int coluns3 = coluns1 * coluns2;

	const int SIZE = 4096;
	const char *name = "Matrix_fst3";
	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	// pid = fork();
	// if (pid == 0) {
	// 	ptr += 6;
	// 	sprintf(ptr, "World!");
	// 	ptr += 7;
	// } else {
	// 	sprintf(ptr, "Hello ");
	// }

	int total = lines3 * coluns3;
	int fst3[lines2][coluns2]; //auxiliar
	int fst4[lines3][coluns3];

	// for (int k = 0; k < 4; k++) {
	// 	if (pid != 0) {
	// 		n+=1;
	// 		pid = fork();
	// 	}
	// 	if (pid == 0) {
	// 		forkeado(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst3, n);
	// 		// if (n == 2)
	// 		// 	ptr += total/4;
	// 		// else if (n == 3)
	// 		// 	ptr += (total/4) * 2 + 4;
	// 		// else if (n == 4)
	// 		// 	ptr += (total/4) * 3 + 6;
	// 		write_fork(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst3, n, ptr);
	// 		exit(0);
	// 	}
	// 	wait(NULL);	
	// }
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++) {
			sprintf(ptr, "%d ", fst[a][b]);
			ptr += 2;
		}
		sprintf(ptr, "\n");
		ptr += strlen("\n");
	}

	consumer(name, SIZE, ptr);
	// fazer todos escreverem em um arquivo diferente, depois passar pra uma so' matrix


    return 0;
}
