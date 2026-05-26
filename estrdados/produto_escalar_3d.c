#include <stdio.h>

typedef struct
{
    float x;
    float y;
    float z;
} Vetor;

float escalar (Vetor* v1 , Vetor* v2 )
{
    if (v1 == NULL || v2 == NULL) return 0.0f;
    return (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
}

int main(void)
{
    Vetor a = {1.0f, 2.0f, 3.0f};
    Vetor b = {4.0f, 5.0f, 6.0f};
    printf("escalar(a, b) = %f\n", escalar(&a, &b));

    Vetor c = {0.5f, -1.0f, 2.0f};
    Vetor d = {-2.0f, 3.0f, 0.0f};
    printf("escalar(c, d) = %f\n", escalar(&c, &d));

    return 0;
}