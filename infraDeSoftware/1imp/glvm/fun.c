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
	return liness;
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
    		  int lines3, int coluns3, int fst3[lines2][coluns2],
			  int filho)
{
	int n = 0, flag = 0;
  
  	int col, row;
    int total = lines3 * coluns3;

    for(int l = 0; l < lines1; l++) { //0
        for(int c = 0; c < coluns1; c++) { //0
            row = l * 2;
            for(int l2 = 0; l2 < lines2; l2++) {
                col = c * 2;
                for(int c2 = 0; c2 < coluns2; c2++) {
                    if (filho == 1 && n < total/4) { //fork(1)
                      fst3[row][col] = fst1[l][c] * fst2[l2][c2];
                      flag = 1;
                    }
                    else if (filho == 2 && n >= total/4 && n < (total/4)*2) { //fork(2)
                      fst3[row][col] = fst1[l][c] * fst2[l2][c2];
                      flag = 1;
                    }
                    else if (filho == 3 && n >= (total/4)*2 && n < (total/4)*3) {
                      fst3[row][col] = fst1[l][c] * fst2[l2][c2]; //fork(3)
                      flag = 1;
                    }
                    else {
                      fst3[row][col] = fst1[l][c] * fst2[l2][c2]; //fork(4)
                      flag = 1;
                    }
                    col+=1;
                    n++;
                }
                row+=1;
            }
            if(flag == 1) {
              return;
            }
        }
    }
  return;
	
}

int exemplo() {
  int fst[4][4] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4};
  int n = 0, flag = 0;
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (n < 16/4) { //fork(1)
        printf("%d ", fst[i][j]);
        flag = 1;
      }
      if (n >= 16/4 && n < (16/4)*2) {
        printf("%d ", fst[i][j]); //fork(2)
        flag = 1;
      }
      if (n >= (16/4)*2 && n < (16/4)*3) {
        printf("%d ", fst[i][j]); //fork(3)
        flag = 1;
      }
      if (n >= (16/4)*3 && n < 16) {
        printf("%d ", fst[i][j]); //fork(4)
        flag = 1;
      }
      n++;
    }
    if(flag == 1) {
      printf("\n");
      return 0;
    }
  }
  return 0;
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

void hello() {
	const int SIZE = 4096;
	const char *name = "OS";
	const char *message_0 = "Hello";
	const char *message_1 = "World!";
	int shm_fd;
	void *ptr;

	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	sprintf(ptr,"%s",message_0);
	ptr += strlen(message_0);
	sprintf(ptr," %s\n",message_1);
	ptr += strlen(message_1);
	return;
}

void consumer() {
	const int SIZE = 4096;
	const char *name = "OS";
	int shm_fd;
	void *ptr;
	shm_fd = shm_open(name, O_RDONLY, 0666);
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
	printf("%s",(char *)ptr);
	shm_unlink(name);
	return;
}