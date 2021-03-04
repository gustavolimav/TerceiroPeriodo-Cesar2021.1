// SPDX-License-Identifier: GPL-3.0
#include <stdio.h>

int verificar_tamanho(const char arr[]) // tamanho do arquivo = quantidade de elementos ("\0") que existem ate chegar no final
{
	int i = 0;

	while (arr[i] != '\0')
		i++;
	return i;
}
int linhas(FILE *fp) // quantidade de linhas = a quantidade de "\n" mais um
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

int colunas(FILE *fp) // quantidade de colunas = (quantidade de elementos("\0") na primeira linha + um) / dois 
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

int multiplicar_matrizes(int lines1, int coluns1, int fst1[lines1][coluns1],
                        int lines2, int coluns2, int fst2[lines2][coluns2],
                        int fst3[lines1][coluns2])
{  
    //se a quatidade de colunas da primeira matrix for igual a quantidade de linhas
    // da segunda matrix nao sera possivel executar a multiplicacao
    if (coluns1 != lines2) return 1; 

    int a = lines1, b = coluns1, c = coluns2;

    for (int i = 0; i < a; i++) { // multiplicar todas as possibilidades da matrix
        for (int k = 0; k < c; k++) { // ex matrix 2x2: 1L x 1C, 1L x 2C, 2L x 1C e 2L x 2 C
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

	fp = fopen(argv[1], "r"); // abre o arquivo em modo leitura
	lines1 = linhas(fp); // conta as linhas
	fseek(fp, 0, SEEK_SET); // coloca o seek do arquivo no inicio
	coluns1 = colunas(fp); // conta colunas
	fseek(fp, 0, SEEK_SET);

    int fst[lines1][coluns1];

    while (!feof(fp)) {  // enquanto nao chegar o final do arquivo
		for (int a = 0; a < lines1; a++) {
			for (int b = 0; b < coluns1; b++)
				fscanf(fp, "%d", &fst[a][b]); //salva a matrix
		}
	}

    fp = fopen(argv[2], "r");
	lines2 = linhas(fp);!feof
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
			printf("%d ", fst[a][b]); // imprimir a matrix
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

    int final = multiplicar_matrizes(lines1, coluns1, fst, // multiplica a matrix
                                    lines2, coluns2, fst2,
                      		        fst3);

    printf("\n");

    if(final == 1) { // se der erro no multiplicar matrix ele imprime mensagem de erro
        printf("Error: not possible to mult these matrixs");
        return 0;
    }

    for (int a = 0; a < lines1; a++) {
		for (int b = 0; b < coluns2; b++) {
			printf("%d ", fst3[a][b]);
		}
        printf("\n");
	}
	return 0;
}
