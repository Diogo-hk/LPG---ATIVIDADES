#include <stdio.h>

int soma_diferenca(int x, int y);

int main()
{
    int x = 0, y = 0;

    printf("Digite o valor x e y\n");
    scanf("%d", &x);
    scanf("%d", &y);

    printf("A soma é %d\n", soma_diferenca(x+1, y));
    return 0;
}

int soma_diferenca(int x, int y)
{
    int soma = 0;
    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    for (int i = x + 1; i < y; i++)
    {
        if (i % 2 != 0)
        {
            soma += i;
        }
    }
    return soma;
}