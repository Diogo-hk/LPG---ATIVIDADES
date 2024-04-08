#include <stdio.h>

int multiplo(int n, int y, int x);

int main()
{

    int n, k, x;
    printf("Digite quantos somatorios\n");
    scanf("%d", &n);

    printf("Digite o numero que voce quer ver\n");
    scanf(" %d", &k);

    printf("Digite o a partir de:\n");
    scanf(" %d", &x);

    for
    return 0;
}

int multiplo(int n, int k, int x)
{
    if (x < k)
    {
        return 0;
    }

    while (x % k != 0)
    {
        x++;
    }

    for (int i = 0; i < n; i++)
    {
        if (x % k == 0)
        {

        } 
    }
}