/* SPDX-License-Identifier: GPL-3.0 */
#ifndef FILE_H
#define FILE_H

	#include <stdio.h>
	#include <time.h>
	#include <stdlib.h>

	int verificar_tamanho(const char arr[]);
	int linhas(FILE *fp);
	int colunas(FILE *fp);
	
#endif  /*FILE_H*/
