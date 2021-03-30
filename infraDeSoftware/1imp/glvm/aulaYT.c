#include "fun.h"

int main(int argc, char *argv[])
{
	int lines1, coluns1, lines2, coluns2;
	FILE *fp, *fp2, *out;
	clock_t time;

	clock();

	fp = fopen(argv[1], "r");

	if (!fp) {
		printf("Error: First file does not exist\n");
		return 1;
	}

	lines1 = linhas(fp);
	fseek(fp, 0, SEEK_SET);
	coluns1 = colunas(fp, lines1);
	fseek(fp, 0, SEEK_SET);

	if (verify(fp, coluns1, lines2) == -1) {
		printf("ERROR: first matrix invalid");
		fclose(fp);
		return 0;
	}

	fseek(fp, 0, SEEK_SET);

	int fst[lines1][coluns1];

	scan_matrix(fp, lines1, coluns1, fst);

	fclose(fp);

	fp2 = fopen(argv[2], "r");

	if (!fp2) {
		printf("Error: Second file does not exist\n");
		return 1;
	}

	lines2 = linhas(fp2);
	fseek(fp2, 0, SEEK_SET);
	coluns2 = colunas(fp2, lines2);
	fseek(fp2, 0, SEEK_SET);

	if (verify(fp2, coluns2, lines2)==-1) {
		printf("ERROR: Second matrix invalid");
		fclose(fp2);
		return 0;
	}

	fseek(fp2, 0, SEEK_SET);

	int fst2[lines2][coluns2];

	scan_matrix(fp2, lines2, coluns2, fst2);

	int lines3 = lines1 * lines2;
	int coluns3 = coluns1  * coluns2;

	// segunda questao

	int pid, filho = 0;
	const char *name = "Matrix_fst3";
	int shm_fd;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	int total = lines3 * coluns3;

	ftruncate(shm_fd, total);

	char (*fst4)[coluns3];
	int f = 4;

	fst4 = (char(*)[coluns3])mmap(0, total,  PROT_WRITE,   MAP_SHARED,  shm_fd, 0);
	
	filho = 1;
	pid = fork();

	if (pid != 0) {
		filho = 2;
		pid = fork();
	}
	if (pid != 0) {
		filho = 3;
		pid = fork();
	}
	if (pid != 0) {
		filho = 4;
		pid = fork();
	}
	if (pid == 0) {
		forkeado(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst4, filho);
		exit(0);
	}
	wait(NULL);

	//primeira questao

	int fst3[lines3][coluns3];

	serial(lines1, coluns1, fst,
         lines2, coluns2, fst2,
         lines3, coluns3, fst3);

	time = clock();

	fclose(fp2);

	out = fopen("tensor_glvm.out", "w");
	fprintf(out, "1. serial\n");
	for (int a = 0; a < lines3; a++) {

		for (int b = 0; b < coluns3; b++)
			fprintf(out, "%d ", fst3[a][b]);

		fprintf(out, "%s", "\n");
	}

	fprintf(out, "%s %lf%s", "Tempo de execução: "
	, ((double)time) / ((CLOCKS_PER_SEC / 1000)), "ms\n");

	// escrevendo segunda questao no arquivo

	fprintf(out, "2. via múltiplos processos, criados a partir do comando fork(), e utilizando o compartilhamento de memória\n");
	for (int a = 0; a < lines3; a++) {

		for (int b = 0; b < coluns3; b++)
			fprintf(out, "%d ", fst4[a][b]);

		fprintf(out, "%s", "\n");
	}
	
	shm_unlink(name);


	// terceira questao

	int fst5[lines3][coluns3];
	int fd1[2];
	int fd2[2];
	int fd3[2];
	int fd4[2];

	filho = 1;
	pipe (fd1);

    pid = fork();

    if (pid == 0) {
        close(fd1[0]);
        forkeado2(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst5, filho);
        write (fd1[1], fst5, total*sizeof(int));
        close(fd1[1]);
    }
    pipe(fd2);
    if (pid != 0) {
        pid = fork();
        if (pid == 0) {
            close(fd2[0]);
            close(fd1[1]);
            read(fd1[0], fst5, sizeof(int)*total);
            forkeado2(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst5, filho);
            write (fd2[1], fst5, total*sizeof(int));
            close(fd2[1]);
            close(fd1[0]);
        }
    }
    pipe(fd3);
    if (pid != 0) {
        pid = fork();
        if (pid == 0) {
            close(fd3[0]);
            close(fd2[1]);
            read(fd2[0], fst5, sizeof(int)*total);
			forkeado2(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst5, filho);
            write (fd3[1], fst5, total*sizeof(int));
            close(fd3[1]);
            close(fd2[0]);
        }
    }
    pipe(fd4);
    if (pid != 0) {
        pid = fork();
        if (pid == 0) {
            close(fd4[0]);
            close(fd3[1]);
            read(fd3[0], fst5, sizeof(int)*total);
			forkeado2(lines1, coluns1, fst, lines2, coluns2, fst2, lines3, coluns3, fst5, filho);
            write (fd4[1], fst5, total*sizeof(int));
            close(fd4[1]);
            close(fd3[0]);
        }
    }
    
    if (pid != 0) {
        close(fd4[1]);

        read(fd4[0], fst5, sizeof(int)*total);

		printArray(lines3, coluns3, fst5);

        close(fd4[0]);
    }
	exit(0);

	// quarta questao



	fclose(out);

	// printf("\nlines1: %d coluns1: %d\n lines2: %d coluns2: %d\n", lines1, coluns1, lines2, coluns2);

    return 0;
}