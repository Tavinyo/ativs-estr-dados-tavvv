#include <stdio.h>
#include <stdlib.h>

float *reverso(int n, float *v)
{
    float *v_reverso = (float *)malloc(n * sizeof(float));
    if (v_reverso == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        v_reverso[i] = v[n - 1 - i];
    }
    return v_reverso;
}

int main()
{
    float v[] = {1.0, 2.5, 3.04476, 4.991, 6.7};
    int n = sizeof(v) / sizeof(v[0]);
    float *v_reverso = reverso(n, v);
    if (v_reverso != NULL) {
        printf("Vetor original: ");
        for (int i = 0; i < n; i++) {
            printf("%.2f ", v[i]);
        }
        printf("\nVetor reverso: ");
        for (int i = 0; i < n; i++) {
            printf("%.2f ", v_reverso[i]);
        }
        printf("\n");
        free(v_reverso);
    } else {
        printf("Erro na alocação de memória.\n");
    }
    
    return 0;
}