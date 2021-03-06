#include "fun.h"

int verificar_tamanho(const char arr[]) // tamanho do arquivo = quantidade de elementos ("\0") que existem ate chegar no final
{
	int i = 0;

	while (arr[i] != '\0') {
        i++;
    }
    
	return i;
}

int linhas(FILE *fp) // quantidade de linhas = a quantidade de "\n" mais um
{
	char text[200];
	int liness = 0, i, tamanho;

	fread(&text, sizeof(char), 200, fp);

	for (i = 0; i < verificar_tamanho(text); i++) {
		if (text[i] == '\n')
			liness++;
	}
	return liness + 1;
}

int colunas(FILE *fp) // Conta a quantidade colunas de cada linha para saber se o arquivo é
{                     // valido e retorna -1 se não for e a quantidade de colunas se for.
	char text[200];
	int colunas = 0, i, saver = 0, tamanho;

	fread(&text, sizeof(char), 200, fp);

    tamanho = verificar_tamanho(text);

	for (i = 0; i < tamanho; i++) {
		if (text[i] == '\n') {
            if(saver == 0) saver = colunas;         // salva a quantidade da primeira linha

            if(saver != colunas) return -1;         // se for diferente já finaliza

            colunas = 0;
            continue;
        }
        if (text[i + 1] == ' ' || text[i + 1] == '\n' || text[i + 1] == '\0') colunas++;
	}
    if (colunas != saver) return -1;                // se a ultima for diferente finaliza
    return colunas;
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