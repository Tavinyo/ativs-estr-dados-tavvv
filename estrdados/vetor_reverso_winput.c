// não foi pedido que o input fosse feito, mas achei interessante colocar
// para mostrar a aplicação do vetor sendo um input do usuário.
// como a lógica de input é quase sempre a mesma,
// não achei necessário colocar o input para os outros exemplos.

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
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    float *v = (float *)malloc(n * sizeof(float));
    if (v == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%f", &v[i]);
    }
    
    float *v_reverso = reverso(n, v);
    if (v_reverso != NULL) {
        printf("\nVetor original: ");
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

    free(v);
    
    return 0;
}