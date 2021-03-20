#include "fun.h"

int main(int argc, char const *argv[])
{   
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

	if (coluns1 == -1) {
		printf("Error: First matrix is invalid\n");
		fclose(fp);
		return 1;
	}

	int fst[lines1][coluns1];

	while (!feof(fp)) {
		for (int a = 0; a < lines1; a++) {
			for (int b = 0; b < coluns1; b++)
				fscanf(fp, "%d", &fst[a][b]);
		}
	}
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

	if (coluns2 == -1) {
		printf("Error: Second matrix is invalid\n");
		fclose(fp);
		return 1;
	}

	int fst2[lines2][coluns2];

	while (!feof(fp)) {
		for (int a = 0; a < lines2; a++) {
			for (int b = 0; b < coluns2; b++)
				fscanf(fp, "%d", &fst2[a][b]);
		}
	}

	int pid = 1;
	int n = 0;
	int lines3 = lines1 * lines2;
	int coluns3 = coluns1 * coluns2;
	int fst3[lines3][coluns3];

	// um filho por vez
	// for (int k = 0; k < 4; k++) {
	// 	if (pid != 0) {
	// 		n+=1;
	// 		pid = fork();
	// 	}
	// 	if (pid == 0) {
	// 		forkeado(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst3, n);
	// 		exit(0);
	// 	}
	// 	wait(NULL);	
	// }
	// printArray();
	printf("%d %d %d %d", lines1, coluns1, lines2, coluns2);
    return 0;
}

