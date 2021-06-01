#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void find_start(int **a, int m, int n, int *x0, int *y0)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 2)
            {
                *x0 = i;
                *y0 = j;
            }
}

int valid(int **sol, int **visited, int m, int n, int x, int y)
{
    if (x < 0 || x == m)
        return 0;
    if (y < 0 || y == n)
        return 0; 
    if (sol[x][y] == 1)
        return 0;
    if (visited[x][y] == 1)
        return 0;

    return 1;
}

void solve_lab_rec(FILE *f, int **sol, int **visited, int m, int n, int x, int y)
{
    if (sol[x][y] == 3)
    {
        print_matrix(f, sol, m, n);
        return;
    }

    //try to go up
    if (valid(sol, visited, m, n, x - 1, y))
    {
        visited[x][y] = 1;
        if (sol[x][y] != 2)
            sol[x][y] = 4;
        solve_lab_rec(f, sol, visited, m, n, x - 1, y);

        //backtrack
        if (sol[x][y] != 2)
            sol[x][y] = 0;
        visited[x][y] = 0;
    }

    //try to go down
    if (valid(sol, visited, m, n, x + 1, y))
    {
        visited[x][y] = 1;
        if (sol[x][y] != 2)
            sol[x][y] = 5;
        solve_lab_rec(f, sol, visited, m, n, x + 1, y);
            
        //backtrack
        if (sol[x][y] != 2)
            sol[x][y] = 0;
        visited[x][y] = 0;
    }

    //try to go left
    if (valid(sol, visited, m, n, x, y - 1))
    {
        visited[x][y] = 1;
        if (sol[x][y] != 2)
            sol[x][y] = 6;
        solve_lab_rec(f, sol, visited, m, n, x, y - 1);

        //backtrack
        if (sol[x][y] != 2)
            sol[x][y] = 0;
        visited[x][y] = 0;
    }

    //try to go right
    if (valid(sol, visited, m, n, x, y + 1))
    {
        visited[x][y] = 1;
        if (sol[x][y] != 2)
            sol[x][y] = 7;
        solve_lab_rec(f, sol, visited, m, n, x, y + 1);

        //backtrack
        if (sol[x][y] != 2)
            sol[x][y] = 0;
        visited[x][y] = 0;
    }

    //STATES
    //0 = path
    //1 = wall x
    //2 = start S
    //3 = finnish F
    //4 = up ^
    //5 = down v
    //6 = left <
    //7 = right >
}

int **solve_lab(char output_file[], int **a, int m, int n)
{
    int **sol, **visited, x0, y0;
    FILE *f;
    f = fopen(output_file, "wt");

    sol = alloc_matrix(m, n);
    visited = alloc_matrix(m, n);
    matrix_cpy(sol, a, m, n);
    matrix_cpy(visited, a, m, n);

    find_start(a, m, n, &x0, &y0);
    solve_lab_rec(f, sol, visited, m, n, 1, 0);

    free_matrix(visited, m);
    fclose(f);
    return sol;
}

int main()
{
    int **a, **sol, m, n;
    FILE *f;
    f = fopen("labyrinth.txt", "wt");
    a = get_lab("input.txt", &m, &n);
    print_matrix(f, a, m, n);
    sol = solve_lab("solved_lab", a, m, n);

    fclose(f);
    free_matrix(a, m);
    free_matrix(sol, m);

    return 0;
}