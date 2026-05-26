#include <stdio.h>
#include <stdlib.h>

float **ti_cria(int n) {
    if (n <= 0) return NULL;

    float **mat = (float **)malloc(n * sizeof(float *));
    if (mat == NULL) return NULL;

    for (int i = 0; i < n; i++) {
        mat[i] = (float *)malloc((i + 1) * sizeof(float));
        if (mat[i] == NULL) {
            while (i-- > 0) {
                free(mat[i]);
            }
            free(mat);
            return NULL;
        }

        for (int j = 0; j <= i; j++) {
            mat[i][j] = 0.0f;
        }
    }
    return mat;
}

void ti_atribui(int n, float **mat, int i, int j, float x) {
    if (mat == NULL || i < 0 || i >= n || j < 0 || j >= n) return;
    
    if (i >= j) {
        mat[i][j] = x;
    }
}

float ti_acessa(int n, float **mat, int i, int j) {
    if (mat == NULL || i < 0 || i >= n || j < 0 || j >= n) return 0.0f;
    
    if (i >= j) {
        return mat[i][j];
    }
    return 0.0f;
}

void ti_libera(int n, float **mat) {
    if (mat == NULL) return;
    
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main(void) {
    int n = 5;
    float **mat = ti_cria(n);

    if (!mat) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            ti_atribui(n, mat, i, j, (float)(i * 10 + j + 1));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6.1f ", ti_acessa(n, mat, i, j));
        }
        printf("\n");
    }

    ti_libera(n, mat);
    return 0;
}