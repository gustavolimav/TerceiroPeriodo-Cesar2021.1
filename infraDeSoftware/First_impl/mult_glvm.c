// SPDX-License-Identifier: GPL-3.0
#include "fun.h"

int main(int argc, char *argv[])
{   
    int lines1, coluns1, lines2, coluns2;
	FILE *fp, *out;
    clock_t time;

    clock(); 								// tempo inicial

	fp = fopen(argv[1], "r"); 				// abre o arquivo um em modo leitura
	if(fp == NULL) {
 	 	printf("Error: First file does not exist \n"); // verifica se arquivo um existe
  		return 1;
 	}
	lines1 = linhas(fp); 					// conta as linhas
	fseek(fp, 0, SEEK_SET); 				// coloca o seek no inicio do arquivo novamente
	coluns1 = colunas(fp); 					// conta colunas
	fseek(fp, 0, SEEK_SET);

	if(coluns1 == -1) { 					// se a quantida de colunas for incoerente o programa finaliza
		printf("Error: First matrix is invalid \n");
		fclose(fp);
		return 1;
	}

    int fst[lines1][coluns1]; // inicializa primeira matrix

    while (!feof(fp)) {  					// enquanto não chegar o final do arquivo
		for (int a = 0; a < lines1; a++) {
			for (int b = 0; b < coluns1; b++)
				fscanf(fp, "%d", &fst[a][b]); //guarda matrix1
		}
	}

    fp = fopen(argv[2], "r");				// abre o arquivo dois em modo leitura
	if(fp == NULL) {
 	 	printf("Error: Second file does not exist \n"); // verifica se arquivo dois existe
  		return 1;
 	}
	lines2 = linhas(fp);					// conta as linhas
	fseek(fp, 0, SEEK_SET);					// coloca o seek no inicio do arquivo novamente
	coluns2 = colunas(fp);					// conta colunas
	fseek(fp, 0, SEEK_SET);

	if(coluns2 == -1) { 					// se a quantida de colunas for incoerente o programa finaliza
		printf("Error: Second matrix is invalid \n");
		fclose(fp);
		return 1;
	}
	printf("colons1: %d, lines2: %d lines1 %d\n", coluns1, lines2, lines1);
    int fst2[lines2][coluns2]; // inicializa segunda matrix

    while (!feof(fp)) {
		for (int a = 0; a < lines2; a++) {
			for (int b = 0; b < coluns2; b++)
				fscanf(fp, "%d", &fst2[a][b]); // guarda segunda matrix
		}
	}
    int fst3[lines1][coluns2]; // inicializa terceira matrix

    int final = multiplicar_matrizes(lines1, coluns1, fst, // multiplica as matrixs
                                    lines2, coluns2, fst2,
                      		        fst3);

    printf("\n");

    if(final == 1) { 						// se der erro no multiplicar matrix ele imprime mensagem de erro
        printf("Error: not possible to mult these matrixs \n"); 
		fclose(fp);
        return 0;
    }

    time = clock(); // tempo final - inicial

	out = fopen("mult_glvm.out", "w"); // criação de arquivo de saída
	char cbarra_n = '\n';

	for (int a = 0; a < lines1; a++) {
		for (int b = 0; b < coluns2; b++) {
			fprintf(out, "%d ", fst3[a][b]); // escrever no arquivo
		}
		fprintf(out, "%s", "\n");
	}
	fprintf(out, "%s %lf%s", "Tempo de execução: ", ((double)time)/((CLOCKS_PER_SEC/1000)), "ms");
	fclose(out); // fechar arquivos
	fclose(fp);
	return 0; //finalizar programa
}
