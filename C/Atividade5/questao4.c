#include <stdio.h>

void calcula_hora(int totalMinutos, int *pHora, int *pMinutos);

int main()
{
    int totalMinutos = 0, hora = 0, minutos = 0;
    int *pHora = &hora, *pMinutos = &minutos;
    printf("Digite o total de minutos\n");
    scanf("%d", &totalMinutos);

    calcula_hora(totalMinutos, pHora, pMinutos);

    printf("São %d:%d\n", *pHora, *pMinutos);
}

void calcula_hora(int totalMinutos, int *pHora, int *pMinutos)
{
    int resto = 0;
    *pHora = totalMinutos / 60;
    *pMinutos = totalMinutos % 60;
}