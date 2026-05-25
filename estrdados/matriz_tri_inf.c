#include <stdio.h>
#include <stdlib.h>

static float **ti_mat = NULL;
static int ti_n = 0;

float **ti_cria(int n)
{
    int i, j;
    float **mat = NULL;

    if (n <= 0) return NULL;

    mat = malloc(n * sizeof(float *));
    if (!mat) return NULL;

    for (i = 0; i < n; i++) {
        mat[i] = malloc((i + 1) * sizeof(float));
        if (!mat[i]) {
            while (i-- > 0)
                free(mat[i]);
            free(mat);
            return NULL;
        }
        for (j = 0; j <= i; j++)
            mat[i][j] = 0.0f;
    }

    ti_mat = mat;
    ti_n = n;
    return mat;
}

void ti_atribui(int i, int j, float x)
{
    if (!ti_mat || i < 0 || i >= ti_n || j < 0 || j >= ti_n) return;
    if (j > i) return;
    ti_mat[i][j] = x;
}

float ti_acessa(int i, int j)
{
    if (!ti_mat || i < 0 || i >= ti_n || j < 0 || j >= ti_n) return 0.0f;
    if (j > i) return 0.0f;
    return ti_mat[i][j];
}

void ti_libera(int n, float **mat)
{
    int i;
    if (!mat) return;
    for (i = 0; i < n; i++) 
        free(mat[i]);
    free(mat);
    if (mat == ti_mat) {
        ti_mat = NULL;
        ti_n = 0;
    }
}

int main(void)
{
    int n = 10;
    int i, j;
    float **mat = ti_cria(n);

    if (!mat) {
        fprintf(stderr, "Falha ao alocar matriz\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            ti_atribui(i, j, (float)(i * 10 + j + 1));

    printf("Matriz triangular inferior %d x %d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%6.1f", ti_acessa(i, j));
        printf("\n");
    }

    ti_libera(n, mat);
    return 0;
}