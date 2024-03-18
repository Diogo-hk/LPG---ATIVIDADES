#include <stdio.h>

int main()
{
    int N = 0, B = 0, somador = 0;

    printf("Digite quantas quantidades de casos\n");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("Digite seu numero:\n");
        scanf("%d", &B);
        getchar();

        if (B > 0)
        {
            for (int j = 0; j <= B; j++)
            {
                if(j % 2 != 0)
                {
                    somador += j;
                }
            }
        }

        if (B < 0)
        {
            for (int j = 0; j >= B; j--)
            {
                if (j % 2 != 0)
                {
                    somador = somador + (j);
                }
            }
        }
    }

    printf("A soma é %d\n", somador);
}