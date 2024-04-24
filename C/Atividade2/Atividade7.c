#include <stdio.h>

int multiplo(int n, int k, int x);

int main()
{
    int n, k, x;
    printf("Digite quantos somatorios: ");
    scanf("%d", &n);

    printf("Digite o numero que voce quer ver: ");
    scanf("%d", &k);

    printf("Digite a partir de: ");
    scanf("%d", &x);

    printf("O somatório é: %d\n", multiplo(n, k, x));
    return 0;
}

int multiplo(int n, int k, int x)
{
    if (k == 0)
    {
        return 0;
    }

    int somatorio = 0, contador = 0;

    for (int i = x; contador < n; i++)
    {
        if (i % k == 0)
        {
            somatorio += i;
            contador++;
        }
    }

    return somatorio;
}
