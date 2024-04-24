#include <stdio.h>

int main()
{
    int N = 0, B = 0, somador = 0;

    printf("Digite o primeiro numero:\n");
    scanf("%d", &N);

    printf("Digite o segundo numero:\n");
    scanf("%d", &B);

    if (N > 0)
    {
        for (int i = 0; i <= N; i++)
        {
            if(i % 2 != 0)
            {
                somador += i;
            }
        }
    }

    if (B > 0)
    {
        for (int i = 0; i <= B; i++)
        {
            if (i % 2 != 0)
            {
                somador += i;
            }
        }
    }

    if (N < 0)
    {
        for (int i = 0; i >= N; i--)
        {
            if (i % 2 != 0)
            {
                somador = somador + (i);
            }
        }
    }

    if (B < 0)
    {
        for (int i = 0; i >= B; i--)
        {
            if (i % 2 != 0)
            {
                somador = somador + (i);
            }
        }
    }

    printf("SOMA: %d", somador);
}