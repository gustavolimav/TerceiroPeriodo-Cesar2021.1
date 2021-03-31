// SPDX-License-Identifier: GPL-3.0
#include "fun.h"

int verificar_tamanho(const char arr[])
{
	int i = 0;

	while (arr[i] != '\0')
		i++;

	return i;
}

int linhas(FILE *fp)
{
	int liness = 0, i, c;

	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == '\n')
			liness++;
	}
	return liness;
}

int colunas(FILE *fp, int lines)
{
	char text[90000];
	int colunas = 0, i, tamanho;

	fread(&text, sizeof(char), 90000, fp);

	tamanho = verificar_tamanho(text);

	if (tamanho == 1)
		return 1;

	for (i = 0; i < tamanho; i++) {
		if (text[i + 1] == ' ' || text[i + 1] == '\0') {
			colunas++;
		} else if (text[i + 1] == '\n') {
			colunas++;
			return colunas;
		}
	}
	return colunas;
}

int verify(FILE *fp, int coluns, int lines)
{
	char text[90000];
	int colunas = 0, i, tamanho, row = 0;

	fread(&text, sizeof(char), 90000, fp);

	tamanho = verificar_tamanho(text);

	if (tamanho == 1)
		return 1;

	for (i = 0; i < tamanho; i++) {
		if (text[i + 1] == ' ' || text[i + 1] == '\0') {
			colunas++;
		} else if (text[i + 1] == '\n') {
			row++;
			if (text[i] != ' ')
				colunas++;

			if (coluns != colunas)
				return -1;

			if (row == lines)
				return 1;

			colunas = 0;
		}
	}
	return colunas;
}

void serial(int lines1, int coluns1, int fst1[lines1][coluns1],
	    int lines2, int coluns2, int fst2[lines2][coluns2],
	    int lines3, int coluns3, int fst3[lines3][coluns3])
{
	int col, row;

	for (int l = 0; l < lines1; l++) { //0
		for (int c = 0; c < coluns1; c++) { //0
			row = l * lines2;
			for (int l2 = 0; l2 < lines2; l2++) {
				col = c * coluns2;
				for (int c2 = 0; c2 < coluns2; c2++) {
					fst3[row][col] = fst1[l][c]
					* fst2[l2][c2];
					col += 1;
				}
				row += 1;
			}
		}
	}
}

void forkeado(int lines1, int coluns1, int fst1[lines1][coluns1],
	      int lines2, int coluns2, int fst2[lines2][coluns2],
		  int lines3, int coluns3, char fst3[lines3][coluns3],
		  int filho)
{
	int col, row, flag = 0, n = 0;
	int total = lines3 * coluns3;

	for (int l = 0; l < lines1; l++) { //0
		for (int c = 0; c < coluns1; c++) { //0
			row = l * lines2;
			for (int l2 = 0; l2 < lines2; l2++) {
				col = c * coluns2;
				for (int c2 = 0; c2 < coluns2; c2++) {
					if (filho == 1 &&
					    (n < total / 4)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2]; //fork(1)
						flag = 1;
					} else if (filho == 2 &&
						(n >= total / 4) &&
						(n < (total / 4) * 2)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2]; //fork(2)
						flag = 1;
					} else if (filho == 3 &&
						(n >= (total / 4) * 2) &&
						(n < (total / 4) * 3)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2]; //fork(3)
						flag = 1;
					} else if (filho == 4 &&
						(n >= (total / 4) * 3) &&
						(n < total)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2];  //fork(4)
						flag = 1;
					}
					col++;
					n++;
				}
				row++;
			}
		}
	}
}

void forkeado2(int lines1, int coluns1, int fst1[lines1][coluns1],
	       int lines2, int coluns2, int fst2[lines2][coluns2],
	       int lines3, int coluns3, int fst3[lines3][coluns3],
	       int filho)
{
	int col, row, flag = 0, n = 0;
	int total = lines3 * coluns3;

	for (int l = 0; l < lines1; l++) { //0
		for (int c = 0; c < coluns1; c++) { //0
			row = l * lines2;
			for (int l2 = 0; l2 < lines2; l2++) {
				col = c * coluns2;
				for (int c2 = 0; c2 < coluns2; c2++) {
					if (filho == 1 &&
					    (n < total / 4)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2]; //fork(1)
						flag = 1;
					} else if (filho == 2 &&
						(n >= total / 4) &&
						(n < (total / 4) * 2)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2]; //fork(2)
						flag = 1;
					} else if (filho == 3 &&
						(n >= (total / 4) * 2) &&
						(n < (total / 4) * 3)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2]; //fork(3)
						flag = 1;
					} else if (filho == 4 &&
						(n >= (total / 4) * 3) &&
						(n < total)) {
						fst3[row][col] = fst1[l][c]
						* fst2[l2][c2];  //fork(4)
						flag = 1;
					}
					col++;
					n++;
				}
				row++;
			}
		}
	}
}

void scan_matrix(FILE *fp, int lines, int coluns, int fst[lines][coluns])
{
	while (!feof(fp)) {
		for (int a = 0; a < lines; a++) {
			for (int b = 0; b < coluns; b++)
				fscanf(fp, "%d", &fst[a][b]);
		}
	}
}
