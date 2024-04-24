#include <stdio.h>

float soma_iterativa(int n);
float soma_recursiva(int n);

int main()
{
    int n = 0;
    printf("Digite o valor de N\n");
    scanf("%d", &n);

    printf("O resultado é %.2f\n", soma_iterativa(n));
    printf("O resultado é %.2f\n", soma_recursiva(n));
}

float soma_iterativa(int n)
{
    float soma = 0;
    for (int i = 1; i < n+1; i++)
    {
        soma = (soma + (1.0 / i));
    }
    return soma;
}

float soma_recursiva(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return (1.0/n) + soma_recursiva(n - 1);
    }
}