#include <stdio.h>
#include <stdlib.h>

int * somente_pares(int n, int *v, int *npares)
{
    *npares = 0;
    
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            (*npares)++;
        }
    }

    int *resultado = (int *)malloc(*npares * sizeof(int));
    
    if (resultado == NULL) {
    return NULL; 
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            resultado[j] = v[i];
            j++;
        }
    }
    
    return resultado;
}

int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int npares = 0;
    
    int *pares = somente_pares(n, vetor, &npares);
    
    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\nElementos pares (%d): ", npares);
    for (int i = 0; i < npares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");
    
    free(pares);
    
    return 0;
}