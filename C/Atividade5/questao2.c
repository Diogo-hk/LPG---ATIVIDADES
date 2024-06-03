#include <stdio.h>

void troca_valor(float *x, float *y);

int main()
{
    float a = 0, b = 0;
    float *numeroUm = &a, *numeroDois = &b;
    printf("Digite o valor do primeiro numero\n");
    scanf("%f", numeroUm);
    printf("Digite o segundo valor\n");
    scanf("%f", numeroDois);

    printf("Numero A: %f, Numero B: %f\n\n", *numeroUm, *numeroDois);
    troca_valor(numeroUm, numeroDois);
    printf("Numero A: %f, Numero B: %f\n", *numeroUm, *numeroDois);
}

void troca_valor(float *x, float *y)
{
    float auxliar = 0;
    auxliar = *x;
    *x = *y;
    *y = auxliar;

}