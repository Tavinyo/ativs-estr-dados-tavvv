#include <stdio.h>
#include <stdlib.h>

static float **ts_mat = NULL;
static int ts_n = 0;

float **ts_cria(int n)
{
    int i, j;
    float **mat = NULL;

    if (n <= 0) return NULL;

    mat = malloc(n * sizeof(float *));
    if (!mat) return NULL;

    for (i = 0; i < n; i++) {
        mat[i] = malloc((n - i) * sizeof(float));
        if (!mat[i]) {
            while (i-- > 0)
                free(mat[i]);
            free(mat);
            return NULL;
        }
        for (j = 0; j < n - i; j++)
            mat[i][j] = 0.0f;
    }

    ts_mat = mat;
    ts_n = n;
    return mat;
}

void ts_atribui(int i, int j, float x)
{
    if (!ts_mat || i < 0 || i >= ts_n || j < 0 || j >= ts_n) return;
    if (j < i) return;
    ts_mat[i][j - i] = x;
}

float ts_acessa(int i, int j)
{
    if (!ts_mat || i < 0 || i >= ts_n || j < 0 || j >= ts_n) return 0.0f;
    if (j < i) return 0.0f;
    return ts_mat[i][j - i];
}

void ts_libera(int n, float **mat)
{
    int i;
    if (!mat) return;
    for (i = 0; i < n; i++) 
        free(mat[i]);
    free(mat);
    if (mat == ts_mat) {
        ts_mat = NULL;
        ts_n = 0;
    }
}

int main()
{
    int n = 10;
    int i, j;
    float **mat = ts_cria(n);

    if (!mat) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            ts_atribui(i, j, (float)(i * 10 + j - i));
        }
    }

    printf("Matriz triangular superior %d x %d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%6.2f ", ts_acessa(i, j));
        }
        printf("\n");
    }

    ts_libera(n, mat);
    return 0;
}