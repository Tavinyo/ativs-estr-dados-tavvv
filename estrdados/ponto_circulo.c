#include <stdio.h>
#include <math.h>

typedef struct ponto Ponto;
struct ponto
{
    float x, y;
};

typedef struct circulo Circulo;
struct circulo
{
    Ponto c; 
    float r;
};

int intersecao(Circulo* a, Circulo* b)
{
    float dx = a->c.x - b->c.x;
    float dy = a->c.y - b->c.y;
    float distancia = sqrt(dx * dx + dy * dy);
    
    return (distancia <= a->r + b->r) ? 1 : 0;
}

float comprimento(int n, Ponto* v)
{
    if (n < 2) return 0.0;
    
    float total = 0.0;
    for (int i = 0; i < n-1; i++) {
        float dx = v[i+1].x - v[i].x;
        float dy = v[i+1].y - v[i].y;
        total += sqrt(dx * dx + dy * dy);
    }
    
    return total;
}

int main()
{
    Circulo c1 = {{0.0f, 0.0f}, 5.0f};
    Circulo c2 = {{3.0f, 4.0f}, 2.0f};
    Circulo c3 = {{10.0f, 10.0f}, 1.0f};
    
    printf("Círculo 1 e 2 se interceptam? %s\n", 
           intersecao(&c1, &c2) ? "Sim" : "Não");
    printf("Círculo 1 e 3 se interceptam? %s\n", 
           intersecao(&c1, &c3) ? "Sim" : "Não");
    
    Ponto pontos[] = {{0.0, 0.0}, {3.0, 4.0}, {6.0, 0.0}};
    int n = 3;
    
    printf("Comprimento da poligonal: %.2f\n", comprimento(n, pontos));
    
    return 0;
}