#include <stdio.h>

void inc_dec(int *a, int *b);

int main()
{
    int a = 0, b = 0;
    int *numeroUm = &a, *numeroDois = &b;
    printf("Digite os valor A\n");
    scanf("%d", numeroUm);
    printf("Digite o segundo valor B\n");
    scanf("%d", numeroDois);

    inc_dec(numeroUm, numeroDois);

    printf("O valor A: %d, o valor B: %d", *numeroUm, *numeroDois);
}

void inc_dec(int *a, int *b)
{
    (*a)++;
    (*b)--;
}