#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int **alloc_matrix(int m, int n)
{
    int **a, i;

    a = (int **)malloc(m * sizeof(int *));
    //memory_test(a);
    for (i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        //memory_test(a[i]);
    }
    return a;
}

void free_matrix(int **a, int m)
{

    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}

int **get_lab(char input_file[], int *m, int *n)
{
    int **a;

    FILE *f;

    f = fopen(input_file, "rt");

    fscanf(f, "%d", m);
    fscanf(f, "%d", n);
    //printf("%d %d", *m,*n);
    a = alloc_matrix(*m, *n);

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            fscanf(f, "%d", &a[i][j]);

    fclose(f);
    return a;
}

void print_matrix(FILE *f, int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
                fprintf(f, "  ");
            else if (a[i][j] == 1)
                fprintf(f, "x ");
            else if (a[i][j] == 2)
                fprintf(f, "S ");
            else if (a[i][j] == 3)
                fprintf(f, "F ");
            else if (a[i][j] == 4)
                fprintf(f, "^ ");
            else if (a[i][j] == 5)
                fprintf(f, "v ");
            else if (a[i][j] == 6)
                fprintf(f, "< ");
            else if (a[i][j] == 7)
                fprintf(f, "> ");
        fprintf(f, "\n");
        //0 = path
        //1 = wall x
        //2 = start S
        //3 = finnish F
        //4 = up ^ (only after lab is solved)
        //5 = down v (only after lab is solved)
        //6 = left < (only after lab is solved)
        //7 = right > (only after lab is solved)
    }
    fprintf(f, "\n\n\n");
}

void matrix_cpy(int **dest, int **src, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dest[i][j] = src[i][j];
}