#include "fun.h"

int main(int argc, char *argv[])
{
	int lines1, coluns1, lines2, coluns2;
	FILE *fp, *out;
	clock_t time;

	clock();

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

    int lines3 = lines1 * lines2;
	int coluns3 = coluns1  * coluns2;
	int fst3[lines3][coluns3];

	int quadrantes = lines1 * coluns1;
	int quant_elem = lines2 * coluns2;
	int i, pid;

	for (i = 0; i < quadrantes; i++) {
		pid = fork();
		if (pid != 0) { //se sou o processo filho: saio do ciclo!
            for (int j = 0; j < lines2; j++) {
				for (int k = 0; j < coluns2; k++) {
					fst3[i * lines2 + j][i * coluns2 + k] = 99;
				}
			}
			break;
        }

	}
    printf("I am : (i=%d),(pid=%d) mypid=%d\n",i, pid, getpid());
    wait(NULL);
	printArray(lines3, coluns3, fst3);
    return 0;
}

    