int **alloc_matrix(int m,int n);
void free_matrix(int **a,int m);
int ** get_lab(char input_file[],int *m, int *n);
void print_matrix(FILE *f, int **a, int m, int n);
void matrix_cpy(int **dest,int **src,int m,int n);