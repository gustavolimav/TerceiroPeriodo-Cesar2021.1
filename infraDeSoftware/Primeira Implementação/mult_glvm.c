// SPDX-License-Identifier: GPL-3.0
#include <stdio.h>

int verificar_tamanho(const char arr[])
{
	int i = 0;

	while (arr[i] != '\0')
		i++;
	return i;
}
int linhas(FILE *fp)
{
	char text[200];
	int liness = 0, i;

	fread(&text, sizeof(char), 200, fp);

	for (i = 0; i < verificar_tamanho(text); i++) {
		if (text[i] == '\n')
			liness++;
	}
	return liness + 1;
}

int colunas(FILE *fp)
{
	char text[200];
	int colunas = 0, i;

	fread(&text, sizeof(char), 200, fp);

	for (i = 0; i < verificar_tamanho(text); i++) {
		if (text[i] == '\n')
			return (colunas + 1) / 2;

		colunas++;
	}
}

int multiplicar_matrizes(int fst1[][MAX], int lines1, int coluns1,
                        int fst2[][MAX], int lines2, int coluns2,
                        int fst3[][MAX], int lines3, int coluns3)
{  
    // Se a quantidade de colunas da primeira matrix for diferente da qunatidade
    // de linhas da segunda matrix não pode ocorrer multiplicação. Se a quantidade
    // de linhas da primeira matrix for diferente da quantidade da matrix resultante
    if (coluns1 != lines2 || lines1 != lines3 || coluns2 != coluns3) return 1; 

    int a = lines1, b = coluns1, c = coluns2;

    for (int i = 0; i < a; i++) {
        for (int k = 0; k < c; k++) {
            fst3[i][k] = 0;
            for (int j = 0; j < b; j++) {
                fst3[i][k] += fst1[i][j] * fst2[j][k];
            }
        }
    }
    return 0;
}
int main(int argc, char *argv[])
{   
    int lines1, coluns1, lines2, coluns2;

	FILE *fp;

	fp = fopen(argv[1], "r");
	lines1 = linhas(fp);
	fseek(fp, 0, SEEK_SET);
	coluns1 = colunas(fp);
	fseek(fp, 0, SEEK_SET);

    int fst[lines1][coluns1];

    while (!feof(fp)) {
		for (int a = 0; a < lines1; a++) {
			for (int b = 0; b < coluns1; b++)
				fscanf(fp, "%d", &fst[a][b]);
		}
	}

    fp = fopen(argv[2], "r");
	lines2 = linhas(fp);
	fseek(fp, 0, SEEK_SET);
	coluns2 = colunas(fp);
	fseek(fp, 0, SEEK_SET);

    int fst2[lines2][coluns2];

    while (!feof(fp)) {
		for (int a = 0; a < lines2; a++) {
			for (int b = 0; b < coluns2; b++)
				fscanf(fp, "%d", &fst2[a][b]);
		}
	}

    for (int a = 0; a < lines1; a++) {
		for (int b = 0; b < coluns1; b++) {
			printf("%d ", fst[a][b]);
		}
        printf("\n");
	}

    printf("\n");

    for (int a = 0; a < lines2; a++) {
		for (int b = 0; b < coluns2; b++) {
			printf("%d ", fst2[a][b]);
		}
        printf("\n");
	}

    int fst3[lines1][coluns2];

    int final = multiplicar_matrizes(fst[lines1][coluns1], lines1, coluns1,
                                    fst2[lines2][coluns2], lines2, coluns2,
                                    fst3[lines1][coluns2], lines1, coluns2);

    printf("\n");

    for (int a = 0; a < lines1; a++) {
		for (int b = 0; b < coluns2; b++) {
			printf("%d ", fst3[a][b]);
		}
        printf("\n");
	}
	return 0;
}