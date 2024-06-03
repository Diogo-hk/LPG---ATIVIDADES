#include <stdio.h>

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main()
{
    float raio, perimetro, area;
    float *pPerimetro = &perimetro, *pArea = &area;
    printf("Digite o raio e tals\n");
    scanf("%f", &raio);

    calcula_circulo(raio, pPerimetro, pArea);

    printf("O perimetro: %f, a Area : %f\n", *pPerimetro, *pArea);
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea)
{
    *pPerimetro = 2 * 3.14159265359 * raio;
    *pArea = 3.14159265359 * (raio * raio);
}