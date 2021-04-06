/* SPDX-License-Identifier: GPL-3.0 */
#ifndef FILE_H
#define FILE_H

	#include <stdio.h>
	#include <time.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/wait.h>
	#include <stdio.h>
	#include <fcntl.h>
	#include <sys/shm.h>
	#include <sys/stat.h>
	#include <sys/mman.h>
	#include <pthread.h>

	int verificar_tamanho(const char arr[]);
	int linhas(FILE *fp);
	int colunas(FILE *fp, int lines);
	void serial(int lines1, int coluns1, int fst1[lines1][coluns1],
		    int lines2, int coluns2, int fst2[lines2][coluns2],
		    int lines3, int coluns3, int fst3[lines3][coluns3]);
	void scan_matrix(FILE *fp, int lines, int coluns,
			 int fst[lines][coluns]);
	int verify(FILE *fp, int coluns, int lines);
	void forkeado(int lines1, int coluns1, int fst1[lines1][coluns1],
		      int lines2, int coluns2, int fst2[lines2][coluns2],
			  int lines3, int coluns3, int fst3[lines3][coluns3],
			  int filho);
	void forkeado2(int lines1, int coluns1, int fst1[lines1][coluns1],
		       int lines2, int coluns2, int fst2[lines2][coluns2],
			   int lines3, int coluns3, char fst3[lines3][coluns3],
			   int filho);

#endif  /*FILE_H*/
