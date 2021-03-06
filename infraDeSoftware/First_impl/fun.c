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
	char text[90000];
	int liness = 0, i, tamanho;

	fread(&text, sizeof(char), 90000, fp);

	for (i = 0; i < verificar_tamanho(text); i++) {
		if (text[i] == '\n')
			liness++;
	}
	return liness + 1;
}

int colunas(FILE *fp)
{
	char text[90000];
	int colunas = 0, i, saver = 0, tamanho;

	fread(&text, sizeof(char), 90000, fp);

	tamanho = verificar_tamanho(text);

	for (i = 0; i < tamanho; i++) {
		if (text[i] == '\n') {
			if (saver == 0)
				saver = colunas;

			if (saver != colunas)
				return -1;

			colunas = 0;
			continue;
		}
		if (text[i + 1] == ' ' || text[i + 1] == '\n' ||
		    text[i + 1] == '\0')
			colunas++;
	}
	if (colunas != saver)
		return -1;
	return colunas;
}

int multiplicar_matrizes(int lines1, int coluns1,
			 int fst1[lines1][coluns1], int lines2,
			 int coluns2, int fst2[lines2][coluns2],
			 int fst3[lines1][coluns2])
{
	if (coluns1 != lines2)
		return 1;

	int a = lines1, b = coluns1, c = coluns2;

	for (int i = 0; i < a; i++) {
		for (int k = 0; k < c; k++) {
			fst3[i][k] = 0;
			for (int j = 0; j < b; j++)
				fst3[i][k] += fst1[i][j] * fst2[j][k];
		}
	}
	return 0;
}
