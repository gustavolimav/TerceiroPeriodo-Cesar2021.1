// SPDX-License-Identifier: GPL-3.0
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

	int fst3[lines1][coluns2];

	int final = multiplicar_matrizes(lines1,
	coluns1, fst, lines2, coluns2, fst2, fst3);

	printf("\n");

	if (final == 1) {
		printf("Error: not possible to mult these matrixs\n");
		fclose(fp);
		return 0;
	}

	time = clock();

	out = fopen("mult_glvm.out", "w");
	char cbarra_n = '\n';

	for (int a = 0; a < lines1; a++) {
		for (int b = 0; b < coluns2; b++)
			fprintf(out, "%d ", fst3[a][b]);
		fprintf(out, "%s", "\n");
	}
	fprintf(out, "%s %lf%s", "Tempo de execução: "
	, ((double)time) / ((CLOCKS_PER_SEC / 1000)), "ms");
	fclose(out);
	fclose(fp);
	return 0;
}
