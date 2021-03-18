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

	tamanho = verificar_tamanho(text);

	for (i = 0; i < tamanho; i++) {
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

	if (tamanho == 1)
		return 1;

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

void serial(int lines1, int coluns1, int fst1[lines1][coluns1],
          int lines2, int coluns2, int fst2[lines2][coluns2], 
          int lines3, int coluns3,int fst3[lines3][coluns3]){
    
    int col, row;

    for(int l = 0; l < lines1; l++) { //0
        for(int c = 0; c < coluns1; c++) { //0
            row = l * lines2;
            for(int l2 = 0; l2 < lines2; l2++) {
                col = c * coluns2;
                for(int c2 = 0; c2 < coluns2; c2++) {
                    fst3[row][col] = fst1[l][c] * fst2[l2][c2];
                    col+=1;
                }
                row+=1;
            }
        }
    }
}

void forkeado(int lines1, int coluns1, int fst1[lines1][coluns1],
          	  int lines2, int coluns2, int fst2[lines2][coluns2], 
    		  int fst3[lines2][coluns2], int filho)
			  {
	int col, row;
	int  quant = (lines1*coluns1) % 4, quant1 = (lines1*coluns1)/4;
	
	if (filho == 1)
		int c = 0, l = 0;
	else if (filho == 2)
		int c = 1, l = 0;
	else if (filho == 3)
		int c = 0, l = 1;
	else
		int c = 1, l = 1;
		
    row = l * lines2;
    for(int l2 = 0; l2 < lines2; l2++) {
        col = c * coluns2;
        for(int c2 = 0; c2 < coluns2; c2++) {
            fst3[row][col] = fst1[l][c] * fst2[l2][c2];
            col+=1;
        }
        row+=1;
    }
	
	return;
	
}

void printArray(int lines, int coluns, int fstx[lines][coluns]){

    for(int i = 0; i < lines; i++) {
        printf("%d ", fstx[i][0]);
        for(int j = 1; j < coluns; j++)
            printf("%d ", fstx[i][j]);
        if(i != lines - 1)
            printf("\n");
    }
}