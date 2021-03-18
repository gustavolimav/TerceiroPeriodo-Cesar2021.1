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
    char n[10] = "um";
    int pid = fork();
    int filho = 1;
    
    if (pid != 0) {
        strcpy(n, "dois");
        pid = fork();
        filho = 2;
    }
    if (pid != 0) {
        strcpy(n, "tres");
        pid = fork();
        filho = 3;
    }
    if (pid != 0) {
        strcpy(n, "quatro");
        pid = fork();
        filho = 4;
    }

    if (pid == 0) {
        char str[10] = "test";
        strcat(str, n);

        out = fopen(str, "w");
        char cbarra_n = '\n';
        
        int fst3[lines2][coluns2];
       
        forkeado(lines1, coluns2, fst, lines2, coluns2, fst2, fst3, filho);
        
        // for (int a = 0; a < lines1; a++) {
		//     for (int b = 0; b < coluns2; b++)
		// 	    fprintf(out, "%d ", fst3[a][b]);
		//     fprintf(out, "%s", "\n");
	    // }

        fclose(out);
    }
    return 0;
}

