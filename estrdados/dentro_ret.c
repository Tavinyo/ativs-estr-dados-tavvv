#include <stdio.h>

typedef struct
{
    float x;
    float y;
} Ponto;

int dentroRet(Ponto* v1, Ponto* v2, Ponto* p)
{
    if (v1 == NULL || v2 == NULL || p == NULL)
        return 0;

    // comparações para caso os pontos estejam em qualquer ordem
    float minX = (v1->x < v2->x) ? v1->x : v2->x;
    float maxX = (v1->x > v2->x) ? v1->x : v2->x;
    float minY = (v1->y < v2->y) ? v1->y : v2->y;
    float maxY = (v1->y > v2->y) ? v1->y : v2->y;

    if (p->x >= minX && p->x <= maxX && p->y >= minY && p->y <= maxY)
        return 1;

    return 0;
}

int main(void)
{
    Ponto v1 = {0.0f, 0.0f};
    Ponto v2 = {4.0f, 3.0f};
    Ponto p = {2.0f, 1.5f};

    printf("O ponto p = (%.1f, %.1f) está dentro do retângulo definido por v1 e v2? %s\n",
           p.x, p.y, dentroRet(&v1, &v2, &p) ? "Sim" : "Não");

    v1 = (Ponto){1.0, 0.0};
    v2 = (Ponto){10.0, 3.0};
    p = (Ponto){-2.0, 1.5};

    printf("O ponto p = (%.1f, %.1f) está dentro do retângulo definido por v1 e v2? %s\n",
           p.x, p.y, dentroRet(&v1, &v2, &p) ? "Sim" : "Não");

    return 0;
}