#include <stdio.h>
#include <stdbool.h>

bool eh_primo(int num);

int main()
{
    int k, n;
    printf("Digite o valor de k: ");
    scanf("%d", &k);
    printf("Digite a quantidade de números primos desejada (n): ");
    scanf("%d", &n);

    printf("Os %d primeiros números primos acima de %d são:\n", n, k);

    int contador = 0;
    int num = k + 1; // Inicia a busca de números primos a partir de k + 1
    while (contador < n)
    {
        if (eh_primo(num))
        {
            printf("%d ", num);
            contador++;
        }
        num++;
    }

    return 0;
}

bool eh_primo(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
