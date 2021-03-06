#ifndef  FILE_H
#define  FILE_H

    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>

    int verificar_tamanho(const char arr[]);
    int linhas(FILE *fp);
    int colunas(FILE *fp);
    int multiplicar_matrizes(int lines1, int coluns1, int fst1[lines1][coluns1],
                        int lines2, int coluns2, int fst2[lines2][coluns2],
                        int fst3[lines1][coluns2]);
                        
#endif  /*FILE_H*/