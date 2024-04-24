#include <stdio.h>

int soma_iterativa(int n);
int soma_recursiva(int n);

int main()
{
    int n, start, soma = 0;

    printf("Digite o N\n");
    scanf("%d", &n);

    printf("O valor é : %d\n", soma_iterativa(n));
    printf("O valor é : %d\n", soma_recursiva(n));
}

int soma_iterativa(int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma = soma + (i + 1);
    }
    return soma;
}

int soma_recursiva(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n += soma_recursiva(n - 1);
    }
}
